ROMDATA MAGICIAN version 0.90 - 2011 - by Matt McLemore a.k.a Tempest 


Romdata Magician takes Tempest's System INI files and compares them to QuickPlay's Romdata.dat's for systems you've set up in QuickPlay. It will fill in missing data that exist in the INI files into QuickPlay's Romdata.dats. It can over write or just add to data and you can select how and what is overwritten.


USE:
When run the first time, Romdata Magician will create a Romdata Magician.ini file, prompt you to browse to your Quikplay folder, and to the GoomdMerge System Ini and History Files folder. 


RomData magician will then scan each of the folder that you have set up and named yourself in QuickPlay (i.e.: those folders that are in the DATA directory in the QP directory) and it will use the name of the system stated in the entries in the romdata.dat's in those QuickPlay folders to match up to the appropriate ini file.

You need to pull down the dropdown under CURRENT FOLDER - this will look like the folder structure of your QuickPLay system directories - use it to select which systems romdata you want to work on.


Mostly just leave the options in RomData Magician at the default and press Preview - you'll see what RomData Magicican will do with your romdata.dat for that system.

When you're happy, press save and it will then save out the new romdata.dat into the QP folder you're working in (e.g.: it will save your Genesis romdata.dat in your Genesis folder) - it will rename the old romdata with the date and keep it in the same directory in case you want to go back to it.

When you open QuickPlay you should see the results.

Here's what the options do:

ROMDATA OPTIONS:
In the Over Write column, there are 3 options:
1. No check - never over write. Existing data in the QuickPlay romdat for the system you're looking at will not be over written.
2. Check - Always over write. If there is no data from the ini file, the item will be blank.
3. Gray Check / Blue Box (OS dependent) - Conditional overwrite. If there is no data from the ini file, existing data will not be over written.


SIMPLIFY DATA:
Romdata Magician uses the files in the Keylist folder to determine how to output the data - the data in the ini files themselves are quite messy - for instance there are about 30 different names for certain companies - the keylists standardise them so Activision Corporation, Activision Inc. and Activision US all become 'Activision' - the option 'Simplify Data' in the GUI allows the user to choose on whether or not they would like to have the extended (messed up) names, or the version from the keylists. You probably want this always ticked.


ADD MISSING FROM TITLE:
Since many Goodmerge sets still have the year in the Romname (if you merge with the default options) - Romdata Magician will use any 4-number word in brackets in the romname to try to fill in the year in QP. One time you may not want this is if your doing the GB64 Goodset - this will mess up year. So for this set only, have it unticked. Otherwise always have it ticked. This works the same way for Language.

1-5 WITH TEXT/STARS (1-5)/NUMERIC RANGE/CUSTOM DROPDOWN
This governs how the rating field comes out in the romdata

CONTROL TYPE/PERSPECTIVE/OTHER SYSTEMS/ESRB Dropdown
This governs what data will be shown in QuickPlays 'comments' field in the rom window. 
Control Type - what controller is used in a game.
Perspective -  tells you whether a game is 1st person or 3rd person, etc.
Other Systems - which other systems the game was released for.
ESRB - rating for children - whether the game contains sex/violence/drugs, etc.


LANGUAGE:
The options here are about trying to get different language descriptions in a romname to fill in the language field in QuickPlay correctly.
Langauges are prioritized by position in the list view. 
EG: FIFA 98 - Road to World Cup (Europe) (En,Fr,Es,It,Sv).zip
If the code It (Italian) is higher in the list than any of the other languages (En,Fr,Es,Sv), Italian will be shown as the language for that rom.

When you click on a language in the list, the code(region) and language will be shown in the edit boxes. If desired, you can edit the information in the boxes then click 'Add New' to add a new entry to the list, or 'Replace' to replace the current entry. If a user from France wanted to (s)he could change the language from 'French' to 'Francais'. The items in the list can be re-arranged for priority using the up and down arrows.



and lastly....

[QP system to Ini] section of the ini file

Here is where RomData Magician matches up the system names in QuickPlay to Ini names of the ini files. If you're using the latest QuickPlay E-Find then the system names should match to each ini filename without issue.

So Amtrad CPC=GoodCPC means that RomData Magician will look for an ini file starting with GoodCPC when QuickPlay has a system called Amstrad CPC.
(in fact at the moment the file is called GoodCPC_202_GM_V1.ini)

But you may need to go in here and alter/add anything if you've made/altered your own system names in QuickPlay. Otherwise the defaults should work fine.
