Slateport_Market_Nameless_Cavern_MapScripts::
	.byte 0


enterNamelessCavern::
	lockall
	setvar VAR_TEMP_2, 1
	msgbox enterNamelessCavern_Text_0
	release
	end


spawnAzelf::
	lockall
	playbgm MUS_NONE, FALSE
	setvar VAR_TEMP_0, 1
	playmoncry SPECIES_AZELF, CRY_MODE_NORMAL
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, player_movement
	applymovement 1, azelf_movement
	waitmovement 0
	copyvar VAR_0x8000, VAR_LAST_TALKED
	playmoncry SPECIES_AZELF, CRY_MODE_ENCOUNTER
	msgbox spawnAzelf_Text_0
	waitmoncry
	seteventmon SPECIES_AZELF, 40
	special BattleSetup_StartLegendaryBattle
	specialvar VAR_RESULT, GetBattleOutcome
	setflag FLAG_ENCOUNTERED_AZELF
	releaseall
	return


player_movement:
	emote_exclamation_mark
	step_end

azelf_movement:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

enterNamelessCavern_Text_0:
	.string "Clear air surrounds the area. It's\n"
	.string "lifting your spirits.$"

spawnAzelf_Text_0:
	.string "Azeeeeeeee!!$"
