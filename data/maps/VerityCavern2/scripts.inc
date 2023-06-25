VerityCavern2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerityCavern2_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, VerityCavern2_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

VerityCavern2_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_set FLAG_CAUGHT_MESPRIT, tryHideMesprit
	call_if_unset FLAG_CAUGHT_MESPRIT, tryShowMesprit
	return

VerityCavern2_MapScripts_MAP_SCRIPT_ON_RESUME:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VerityCavern2_OnResume
	return


tryHideMesprit::
	setflag FLAG_HIDE_MESPRIT
	return


tryShowMesprit::
	goto_if_set FLAG_DEFEATED_MESPRIT, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MESPRIT
	return


VerityCavern2_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, tryRemoveMesprit
	return


tryRemoveMesprit::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne tryRemoveMesprit_2
tryRemoveMesprit_1:
	removeobject 1
	return

tryRemoveMesprit_2:
	goto Common_EventScript_NopReturn
	goto tryRemoveMesprit_1


EventScript_Mesprit::
	lock
	faceplayer
	waitse
	delay 20
	playmoncry SPECIES_MESPRIT, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_MESPRIT, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_Mesprit_2
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_Mesprit_3
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_Mesprit_4
EventScript_Mesprit_1:
	setflag FLAG_CAUGHT_MESPRIT
	questmenu QUEST_MENU_SET_ACTIVE, QUEST_1
	release
	end

EventScript_Mesprit_2:
	goto defeatedMesprit2
	goto EventScript_Mesprit_1

EventScript_Mesprit_3:
	goto ranMesprit2
	goto EventScript_Mesprit_1

EventScript_Mesprit_4:
	goto ranMesprit2
	goto EventScript_Mesprit_1


ranMesprit2::
	setvar VAR_0x8004, SPECIES_MESPRIT
	goto Common_EventScript_LegendaryFlewAway
	end


defeatedMesprit2::
	setvar VAR_0x8004, SPECIES_MESPRIT
	goto Common_EventScript_LegendaryFlewAway
	end

