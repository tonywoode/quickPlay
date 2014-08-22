#NoEnv
#SingleInstance Force
SetWorkingDir, %A_ScriptDir%
FileRead, Xml, E:\AHK\My AHK\Emulator Ini Project\ButterFly's Attachments\Mess\hash\a2600.xml
Rom = bbecatch
Pos:= RegexMatch(XML, "s)<software name=""" Rom """>.+?<description>(.+?)</description>", Title)
EndPos := RegexMatch(XML, "</software>","",Pos)
Pos:= RegexMatch(XML, "<year>(.+?)</year>", Year, Pos)
Pos:= RegexMatch(XML, "<publisher>(.+?)</publisher>", Publisher, Pos)
/*		<software name="2pakblac">
        <!-- 2 Pak Special - Black Label -->
		<description>2 Pak Special: Challenge + Surfing (PAL)</description>
		<year>1990</year>
		<publisher>HES</publisher>
		<info name="serial" value="771/333"/>
		<part name="cart" interface="a2600_cart">
			<dataarea name="rom" size="16384">
				<rom name="2 pak special (black) - challenge, surfing.a26" size="16384" crc="07bfb506" sha1="05664dcc45d02ce585cd79d551c5c20fc2c7a833" offset="0" />
			</dataarea>
		</part>
	</software>
*/

MsgBox, %Title1%`n%Year1%`n%Publisher1%
ExitApp