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
	lock
	faceplayer
	msgbox grunt1verity_Text_0
	release
	end


grunt2verity::
	lock
	faceplayer
	msgbox grunt1verity_Text_0
	release
	end


grunt3verity::
	lock
	faceplayer
	msgbox grunt1verity_Text_0
	release
	end


marsverity::
	lock
	faceplayer
	msgbox grunt1verity_Text_0
	trainerbattle_no_intro TRAINER_GSATURN_1, marsverity_Text_0
	release
	end


grunt1verity_Text_0:
	.string "Hey$"

marsverity_Text_0:
	.string "You, my friend, are tough! I can see why\n"
	.string "you defy us so...$"
