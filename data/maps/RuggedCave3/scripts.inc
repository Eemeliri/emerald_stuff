RuggedCave3_MapScripts::
	.byte 0


SneaselRuggedCave3::
	bufferspeciesname 0, SPECIES_SNEASEL
	lock
	faceplayer
	playmoncry SPECIES_SNEASEL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle2 SPECIES_SNEASEL, 25, ITEM_NEVER_MELT_ICE, 2, MOVE_METAL_CLAW, MOVE_ICY_WIND, MOVE_QUICK_ATTACK, MOVE_ICICLE_CRASH, FALSE
	dowildbattle
	release
	end

