Slateport_Market_Nameless_Cavern_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Slateport_Market_Nameless_Cavern_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, Slateport_Market_Nameless_Cavern_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

Slateport_Market_Nameless_Cavern_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_set FLAG_CAUGHT_AZELF, tryHideAzelf
	call_if_unset FLAG_CAUGHT_AZELF, tryShowAzelf
	return

Slateport_Market_Nameless_Cavern_MapScripts_MAP_SCRIPT_ON_RESUME:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NamelessCavern_OnResume
	return


tryHideAzelf::
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 1
	setflag FLAG_HIDE_AZELF
	return


tryShowAzelf::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_DEFEATED_AZELF, Common_EventScript_NopReturn
	setvar VAR_TEMP_1, 0
	return


tryRemoveAzelf::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne tryRemoveAzelf_2
tryRemoveAzelf_1:
	removeobject 1
	return

tryRemoveAzelf_2:
	goto Common_EventScript_NopReturn
	goto tryRemoveAzelf_1


NamelessCavern_OnResume::
	goto_if_set FLAG_SYS_CTRL_OBJ_DELETE, NamelessCavern_OnResume_1
	return

NamelessCavern_OnResume_1:
	goto tryRemoveAzelf
	return


enterNamelessCavern::
	lockall
	setvar VAR_TEMP_2, 1
	msgbox enterNamelessCavern_Text_0
	release
	end


spawnAzelf::
	lockall
	setvar VAR_TEMP_1, 1
	playbgm MUS_NONE, FALSE
	playmoncry SPECIES_AZELF, CRY_MODE_NORMAL
	waitmoncry
	addobject 1
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, player_movement
	waitmovement OBJ_EVENT_ID_PLAYER
	waitse
	applymovement 1, azelf_movement
	waitmovement 0
	playmoncry SPECIES_AZELF, CRY_MODE_ENCOUNTER
	msgbox spawnAzelf_Text_0
	delay 40
	waitmoncry
	seteventmon SPECIES_AZELF, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_LAST_TALKED, 1
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq spawnAzelf_2
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq spawnAzelf_3
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq spawnAzelf_4
spawnAzelf_1:
	setflag FLAG_CAUGHT_AZELF
	returnqueststate QUEST_2
	goto_if_eq VAR_RESULT, 1, startLegendaryQuestAzelf
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_3
	releaseall
	end

spawnAzelf_2:
	goto defeatedAzelf
	goto spawnAzelf_1

spawnAzelf_3:
	goto ranAzelf
	goto spawnAzelf_1

spawnAzelf_4:
	goto ranAzelf
	goto spawnAzelf_1


startLegendaryQuestAzelf::
	startquest QUEST_2
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_3
	release
	end


ranAzelf::
	setvar VAR_0x8004, SPECIES_AZELF
	goto Common_EventScript_LegendaryFlewAway
	end


defeatedAzelf::
	setvar VAR_0x8004, SPECIES_AZELF
	goto Common_EventScript_LegendaryFlewAway
	end


player_movement:
	emote_exclamation_mark
	face_up
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
