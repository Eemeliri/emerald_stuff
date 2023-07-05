FlowerParadise_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FlowerParadise_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, FlowerParadise_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

FlowerParadise_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_set FLAG_CAUGHT_SHAYMIN, tryHideShaymin
	call_if_unset FLAG_CAUGHT_SHAYMIN, tryShowShaymin
	return

FlowerParadise_MapScripts_MAP_SCRIPT_ON_RESUME:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FlowerParadise_OnResume
	return


tryHideShaymin::
	setflag FLAG_HIDE_SHAYMIN
	return


tryShowShaymin::
	goto_if_set FLAG_DEFEATED_SHAYMIN, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_SHAYMIN
	return


FlowerParadise_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, tryRemoveShaymin
	return


tryRemoveShaymin::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne tryRemoveShaymin_2
tryRemoveShaymin_1:
	removeobject 1
	return

tryRemoveShaymin_2:
	goto Common_EventScript_NopReturn
	goto tryRemoveShaymin_1


EventScript_Shaymin::
	lock
	faceplayer
	playmoncry SPECIES_SHAYMIN, CRY_MODE_NORMAL
	msgbox EventScript_Shaymin_Text_0
	waitse
	delay 20
	playmoncry SPECIES_SHAYMIN, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	playmoncry SPECIES_SHAYMIN_SKY, CRY_MODE_ENCOUNTER
	msgbox EventScript_Shaymin_Text_1
	settotemboost 1, 2, 2, 2, 2, 2, 2, 0
	seteventmon SPECIES_SHAYMIN_SKY, 75
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne EventScript_Shaymin_2
EventScript_Shaymin_1:
	setflag FLAG_CAUGHT_SHAYMIN
	addvar VAR_SHAYMIN_QUEST_STATE, 1
	returnqueststate QUEST_2
	goto_if_eq VAR_RESULT, 1, EventScript_StartLegendaryQuestShaymin
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_33
	release
	end

EventScript_Shaymin_2:
	goto ranShaymin
	goto EventScript_Shaymin_1


EventScript_StartLegendaryQuestShaymin::
	startquest QUEST_2
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_33
	release
	end


ranShaymin::
	setvar VAR_0x8004, SPECIES_SHAYMIN
	goto Common_EventScript_LegendaryFlewAway
	end


teleportOutFlowerParadise::
	lock
	msgbox teleportOutFlowerParadise_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq teleportOutFlowerParadise_2
	release
	end

teleportOutFlowerParadise_2:
	warpspinenter MAP_EVER_GRANDE_CITY, 28, 8
	release
	end


EventScript_Shaymin_Text_0:
	.string "Shay.. Shaymin?$"

EventScript_Shaymin_Text_1:
	.string "Shayyy!!$"

teleportOutFlowerParadise_Text_0:
	.string "Touch the stone to return where you\n"
	.string "came from?$"
