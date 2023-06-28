NewMauville_Inside3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside3F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside3F_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

NewMauville_Inside3F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_set FLAG_CAUGHT_ZAPDOS, tryHideZapdos
	call_if_unset FLAG_CAUGHT_ZAPDOS, tryShowZapdos
	return

NewMauville_Inside3F_MapScripts_MAP_SCRIPT_ON_RESUME:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside3F_OnResume
	return


tryHideZapdos::
	setflag FLAG_HIDE_ZAPDOS
	return


tryShowZapdos::
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_ZAPDOS
	return


NewMauville_Inside3F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, tryRemoveZapdos
	return


tryRemoveZapdos::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne tryRemoveZapdos_2
tryRemoveZapdos_1:
	removeobject 1
	return

tryRemoveZapdos_2:
	goto Common_EventScript_NopReturn
	goto tryRemoveZapdos_1


EventScript_Zapdos::
	lock
	faceplayer
	waitse
	delay 20
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_ZAPDOS, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, defeatedZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ranZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ranZapdos
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, ranZapdos
	setflag FLAG_CAUGHT_ZAPDOS
	returnqueststate QUEST_2
	goto_if_eq VAR_RESULT, 1, EventScript_StartLegendaryQuestZapdos
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_2
	release
	end

EventScript_StartLegendaryQuestZapdos::
	startquest QUEST_2
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_2
	release
	end

EventScript_Zapdos_1:
	setflag FLAG_CAUGHT_ZAPDOS
	release
	end

EventScript_Zapdos_2:
	goto defeatedZapdos
	goto EventScript_Zapdos_1

EventScript_Zapdos_3:
	goto ranZapdos
	goto EventScript_Zapdos_1

EventScript_Zapdos_4:
	goto ranZapdos
	goto EventScript_Zapdos_1


ranZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end


defeatedZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end

