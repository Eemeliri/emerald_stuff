VerityCavern_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerityCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

VerityCavern_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_eq VAR_VERITY_CAVERN_STATE, 1, spawnGrunts
	goto_if_eq VAR_VERITY_CAVERN_STATE, 2, spawnMesprit
	goto_if_eq VAR_VERITY_CAVERN_STATE, 0, hideGrunts
	return


spawnGrunts::
	clearflag FLAG_HIDE_VERITY_GRUNTS
	return


hideGrunts::
	setflag FLAG_HIDE_VERITY_GRUNTS
	return


spawnMesprit::
	return


grunt1verity::
	trainerbattle_single TRAINER_VERITY_GRUNT_1, grunt1verity_Text_0, grunt1verity_Text_0
	end


grunt2verity::
	trainerbattle_single TRAINER_VERITY_GRUNT_2, grunt1verity_Text_0, grunt1verity_Text_0
	end


grunt3verity::
	trainerbattle_single TRAINER_VERITY_GRUNT_3, grunt1verity_Text_0, grunt1verity_Text_0
	end


marsverity::
	lock
	faceplayer
	msgbox marsverity_Text_0
	trainerbattle_no_intro TRAINER_GMARS_1, marsverity_Text_1
	release
	end


grunt1verity_Text_0:
	.string "Oh no$"

marsverity_Text_0:
	.string "Hey$"

marsverity_Text_1:
	.string "You, my friend, are tough! I can see why\n"
	.string "you defy us so...$"
