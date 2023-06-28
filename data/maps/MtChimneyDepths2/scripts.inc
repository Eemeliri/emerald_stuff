MtChimneyDepths2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimneyDepths2_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, MtChimneyDepths2_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

MtChimneyDepths2_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_set FLAG_CAUGHT_MOLTRES, tryHideMoltres
	call_if_unset FLAG_CAUGHT_MOLTRES, tryShowMoltres
	return

MtChimneyDepths2_MapScripts_MAP_SCRIPT_ON_RESUME:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtChimneyDepths2_OnResume
	return


tryHideMoltres::
	setflag FLAG_HIDE_MOLTRES
	return


tryShowMoltres::
	goto_if_set FLAG_DEFEATED_MOLTRES, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MOLTRES
	return


MtChimneyDepths2_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, tryRemoveMoltres
	return


tryRemoveMoltres::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne tryRemoveMoltres_2
tryRemoveMoltres_1:
	removeobject 1
	return

tryRemoveMoltres_2:
	goto Common_EventScript_NopReturn
	goto tryRemoveMoltres_1


EventScript_Moltres::
	lock
	faceplayer
	waitse
	delay 20
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_MOLTRES, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, defeatedMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ranMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ranMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_MON_TELEPORTED, ranMoltres
	setflag FLAG_CAUGHT_MOLTRES
	returnqueststate QUEST_2
	goto_if_eq VAR_RESULT, 1, EventScript_StartLegendaryQuestMoltres
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_3
	release
	end

EventScript_StartLegendaryQuestMoltres::
	startquest QUEST_2
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_3
	release
	end

EventScript_Moltres_1:
	setflag FLAG_CAUGHT_MOLTRES
	release
	end

EventScript_Moltres_2:
	goto defeatedMoltres
	goto EventScript_Moltres_1

EventScript_Moltres_3:
	goto ranMoltres
	goto EventScript_Moltres_1

EventScript_Moltres_4:
	goto ranMoltres
	goto EventScript_Moltres_1


ranMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end


defeatedMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end

