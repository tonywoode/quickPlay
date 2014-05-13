#!/usr/bin/perl
#
#
sub announce;
sub CheckMameFileValid;
sub ParseMAMEFile;
sub ParseQPFile;
sub ResetRecord;
sub TranslateAmp;

$QPS = chr(172);
%allrecs = ();
#Preamble
print "\n\n\n\n\n\n\nQuickPlay romdata script by Orfax\n\n\n\n\nMake sure these files are called:\n";
print "Romdata.dat\tand\tmame_details.xml\n\nSee the readme for instructions\n\n\n";
announce;
#Give user choice of behaviour
CHOICE: while ( $AllRoms = <STDIN> )
		{
			chomp($AllRoms);
			if ( ( uc($AllRoms) eq uc("1") ) || ( $AllRoms eq "" ) ) 
				{ 
				last CHOICE ;
				}
			else {
				print "\nYou typed:\t$AllRoms\n\n";
				print "Try again - type either \"1\" or press Return:\t\n\n";
				announce;
				}
		}

		
		
# open MAME XML file
open(XMLFILE, $ARGV[0]) or die "Cannot open MAME XML file\n";
open(QPDATFILE, $ARGV[1]) or die "Cannot open Quickplay dat file\n";

ParseMAMEFile;
ParseQPFile;

close(XMFILE);
close(QPDATFILE);

# open QuickPlay ROMData.dat file for writing
open(NEWQPDATFILE, ">ROMData.dat");
print NEWQPDATFILE "ROM DataFile Version : 1.1\n";

#define some constants used for printing
$c1 = "0";
$c2 = "<IPS>";
$c3 = "</IPS>";

foreach $key (sort keys %allrecs)
{
	$val = $allrecs{$key};

	if ($val->{PARSED} eq "")
	{
		print "!!!!game $val->{NAME} does not have a file associated with it\n";
	}
	if ( ($val->{PARSED} eq "YES") || ($AllRoms) ) {
		print NEWQPDATFILE "$val->{QPNAME}$QPS$val->{NAME}$QPS$val->{CLONEOF}$QPS$QPS$val->{FILE}$QPS$val->{EMULATOR}$QPS$val->{COMPANY}$QPS$val->{YEAR}$QPS$val->{GAMETYPE}$QPS$QPS$val->{LANGUAGE}$QPS$QPS$val->{COMMENT}$QPS$c1$QPS$c1$QPS$c2$QPS$c3$QPS$val->{PLAYERS}$QPS$QPS\n";
	}
}

close(NEWQPDATFILE);




#subroutines
#------------------------------------------------------------------------------
sub announce 
{
print "By Default I will only output roms that are in your input Romdata.dat\n";
print "I can, instead, output ALL the roms that are the input Mame XML you've supplied\n";
print "If you want that, enter '1' now, otherwise hit return\t";
}

#------------------------------------------------------------------------------
# CheckMameFileValid
sub CheckMameFileValid
{
	# check first line for xml version tag
	$line = <XMLFILE>;
	chomp $line;

	if (not $line =~ /^<\?xml version="1.0"\?>$/)
	{
		die "input file not valid XML file\n";
	}

	# check file for mame tag
	while ( (not $line =~ /^<mame build="/) &&
			(not eof XMLFILE) )
	{
		$line = <XMLFILE>;
		chomp $line;
	}

	if (eof XMLFILE)
	{
		die "not a valid MAME XML file\n";
	}
}

#------------------------------------------------------------------------------
# ParseMAMEFile
sub ParseMAMEFile
{
	# check if mame xml file is valid
	CheckMameFileValid;

	# now parse it
	while ($line=<XMLFILE>)
	{
		chomp $line;
		if ($line =~ /<game\s.*name="([^"]*)"\ssourcefile/)
		{
			$rec->{NAME}=TranslateAmp($1);
			if ($line =~ /cloneof="([^"]*)"/)
			{
				$rec->{CLONEOF}=TranslateAmp($1);
			}
		}
		elsif ($line =~/<description>(.*)<\/description>/)
		{
			$rec->{QPNAME}=TranslateAmp($1);
		}
		elsif ($line =~/<year>(.*)<\/year>/)
		{
			$rec->{YEAR}=TranslateAmp($1);
		}
		elsif ($line =~/<manufacturer>(.*)<\/manufacturer>/)
		{
			$rec->{COMPANY}=TranslateAmp($1);
		}
		elsif ($line =~/<driver status="(preliminary|imperfect)" /)
		{
			$rec->{COMMENT}=TranslateAmp($1);
		}
		elsif ($line =~ /^\s*<\/game>$/)
		{
			$allrecs{$rec->{NAME}} = $rec;
			ResetRecord;
		}
	}
}

#------------------------------------------------------------------------------
# ParseQPFile
sub ParseQPFile
{
	# check QP Data file is valid
	$line=<QPDATFILE>;
	chomp $line;
	die "Quickplay data file not valid\n" if (not $line =~ /ROM DataFile Version : /);

	# now parse it ; each line has 19 elements, and the ones we want are:
	# 1  - name
	# 5  - file
	# 6  - emulator
	# 9  - game type
	# 11 - language
	# 18 - number of players
	while ($line=<QPDATFILE>)
	{
		chomp $line;
		if ($line =~ /^([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS([^$QPS]*)$QPS/)
		{
			$file = $5;
			$emulator = $6;
			$gametype = $9;
			$language = $11;
			$players = $18;
			if ($file =~ /([^\\]*)\.zip$/)
			{
  				$name = lc $1;
			}


			# check if we have the game
			if (not exists $allrecs{$name})
			{
				print "!!!!game $name does not exist\n";
			}
			else
			{
				# set the missing fields
				$rec = $allrecs{$name};
				$rec->{FILE} = $file;
				$rec->{EMULATOR} = $emulator;
				$rec->{GAMETYPE} = $gametype;
				$rec->{LANGUAGE} = $language;
				$rec->{PLAYERS} = $players;
				$rec->{PARSED} = "YES";

				# now set any known languages properly
				$rec->{LANGUAGE} = "Japanese" if ($rec->{QPNAME} =~ /\(Japan/i);
				$rec->{LANGUAGE} = "Japanese" if ($rec->{QPNAME} =~ /\(ver JAA/i);
				$rec->{LANGUAGE} = "Japanese" if ($rec->{QPNAME} =~ /\(J /i);
				$rec->{LANGUAGE} = "Japanese" if ($rec->{QPNAME} =~ /\(JPN\)/i);
				$rec->{LANGUAGE} = "Japanese" if ($rec->{QPNAME} =~ / Japan/i);
				$rec->{LANGUAGE} = "French" if ($rec->{QPNAME} =~ /\(France/i);
				$rec->{LANGUAGE} = "French" if ($rec->{QPNAME} =~ /\(French/i);
				$rec->{LANGUAGE} = "German" if ($rec->{QPNAME} =~ /\(German/i);
				$rec->{LANGUAGE} = "Italian" if ($rec->{QPNAME} =~ /\(Ital/i);
				$rec->{LANGUAGE} = "Brazilian Portuguese" if ($rec->{QPNAME} =~ /\(Brazil/i);
				$rec->{LANGUAGE} = "Spanish" if ($rec->{QPNAME} =~ /\(Hispanic/i);
				$rec->{LANGUAGE} = "Spanish" if ($rec->{QPNAME} =~ /\(Spain/i);
				$rec->{LANGUAGE} = "Spanish" if ($rec->{QPNAME} =~ /\(Spanish/i);
				$rec->{LANGUAGE} = "Chinese" if ($rec->{QPNAME} =~ /\(Chin/i);
				$rec->{LANGUAGE} = "Korean" if ($rec->{QPNAME} =~ /\(Korea/i);
			}
		}
	}
}

#------------------------------------------------------------------------------
# ResetRecord
sub ResetRecord
{
	$rec = {
	    NAME      => "",
		QPNAME    => "",
		CLONEOF     => "",
		FILE      => "",
		EMULATOR  => "",
		COMPANY   => "",
		YEAR      => "",
		GAMETYPE  => "",
		LANGUAGE  => "",
		PLAYERS   => "",
		COMMENT   => "",
		PARSED    => "",

	};
}

#------------------------------------------------------------------------------
# TranslateAmp
sub TranslateAmp
{
	my $string = shift(@_);

	$string =~ s/&amp;/&/g;
	$string =~ s/&lt;/</g;
	$string =~ s/&gt;/>/g;

	return $string;
}

