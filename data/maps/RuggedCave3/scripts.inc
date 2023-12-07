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
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq SneaselRuggedCave3_2
SneaselRuggedCave3_1:
	removeobject 1
	release
	end

SneaselRuggedCave3_2:
	setflag FLAG_RUGGED_CAVE3_SNEASEL
	goto SneaselRuggedCave3_1

