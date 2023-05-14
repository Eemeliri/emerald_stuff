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
	setvar VAR_LAST_TALKED, 1
	playmoncry SPECIES_AZELF, CRY_MODE_NORMAL
	waitmoncry
	applymovement OBJ_EVENT_ID_PLAYER, player_movement
	applymovement 1, azelf_movement
	waitmovement 0
	playmoncry SPECIES_AZELF, CRY_MODE_ENCOUNTER
	msgbox spawnAzelf_Text_0
	waitmoncry
	seteventmon SPECIES_AZELF, 40
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq spawnAzelf_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq spawnAzelf_3
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq spawnAzelf_4
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq spawnAzelf_5
spawnAzelf_1:
	setflag FLAG_ENCOUNTERED_AZELF
	releaseall
	end

spawnAzelf_2:
	goto Common_EventScript_RemoveStaticPokemon
	goto spawnAzelf_1

spawnAzelf_3:
	goto Common_EventScript_RemoveStaticPokemon
	goto spawnAzelf_1

spawnAzelf_4:
	goto Common_EventScript_LegendaryFlewAway
	goto spawnAzelf_1

spawnAzelf_5:
	goto Common_EventScript_LegendaryFlewAway
	goto spawnAzelf_1


player_movement:
	emote_exclamation_mark
	step_end

azelf_movement:
	walk_slow_down
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
