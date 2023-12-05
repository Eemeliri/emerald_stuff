RuggedCave_MapScripts::
	.byte 0


phanpyRuggedCave::
	bufferspeciesname 0, SPECIES_PHANPY
	return


zubatRuggedCave::
	bufferspeciesname 0, SPECIES_ZUBAT
	return


RuggedCaveHiker::
	lock
	faceplayer
	msgbox RuggedCaveHiker_Text_0
	release
	end


nemZubat::
	lock
	setwildbattle SPECIES_ZUBAT, 15
	dowildbattle
	setvar VAR_TEMP_2, 1
	release
	end


RuggedCaveHiker_Text_0:
	.string "I heard there was a colder area with\n"
	.string "rare Pokémon further into this cave,\l"
	.string "but I don't have Rock Smash to\l"
	.string "continue...$"
