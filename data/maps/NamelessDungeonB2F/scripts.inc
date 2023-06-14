NamelessDungeonB2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NamelessDungeonB2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, NamelessDungeonB2F_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

NamelessDungeonB2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_set FLAG_CAUGHT_MEWTWO, tryHideMewtwo
	call_if_unset FLAG_CAUGHT_MEWTWO, tryShowMewtwo
	return

NamelessDungeonB2F_MapScripts_MAP_SCRIPT_ON_RESUME:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NamelessDungeonB2F_OnResume
	return


tryHideMewtwo::
	setflag FLAG_HIDE_MEWTWO
	return


tryShowMewtwo::
	goto_if_set FLAG_DEFEATED_MEWTWO, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MEWTWO
	return


NamelessDungeonB2F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, tryRemoveMewtwo
	return


tryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne tryRemoveMewtwo_2
tryRemoveMewtwo_1:
	removeobject 1
	return

tryRemoveMewtwo_2:
	goto Common_EventScript_NopReturn
	goto tryRemoveMewtwo_1


EventScript_Mewtwo::
	lock
	faceplayer
	waitse
	delay 20
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_MEWTWO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_Mewtwo_2
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_Mewtwo_3
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_Mewtwo_4
EventScript_Mewtwo_1:
	setflag FLAG_CAUGHT_MEWTWO
	release
	end

EventScript_Mewtwo_2:
	goto defeatedMewtwo
	goto EventScript_Mewtwo_1

EventScript_Mewtwo_3:
	goto ranMewtwo
	goto EventScript_Mewtwo_1

EventScript_Mewtwo_4:
	goto ranMewtwo
	goto EventScript_Mewtwo_1


GreenMewTransform::
	lockall
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, panToGreen
	waitmovement OBJ_EVENT_ID_CAMERA
	delay 60
	msgbox GreenMewTransform_Text_0
	waitmessage
	delay 30
	playmoncry SPECIES_MEW, CRY_MODE_NORMAL
	msgbox GreenMewTransform_Text_1, MSGBOX_AUTOCLOSE
	applymovement 3, mewJump
	waitmoncry
	delay 30
	playse SE_BALL_OPEN
	removeobject 3
	addobject 4
	setobjectxy 4, 52, 23
	delay 60
	playmoncry SPECIES_DITTO, CRY_MODE_NORMAL
	waitmoncry
	delay 60
	playse SE_BALL_OPEN
	removeobject 4
	delay 30
	setflag FLAG_HIDE_DITTO
	applymovement 2, greenNoticePlayer
	waitmovement 2
	applymovement OBJ_EVENT_ID_CAMERA, panBackFromGreen
	waitmovement OBJ_EVENT_ID_CAMERA
	delay 60
	special RemoveCameraObject
	setvar VAR_NAMELESS_DUNGEON_GREEN_STATE, 1
	releaseall
	return


panToGreen:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

mewJump:
	jump_in_place_left
	step_end

greenNoticePlayer:
	emote_exclamation_mark
	delay_16
	delay_16
	face_left
	step_end

panBackFromGreen:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

ranMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end


defeatedMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end


GreenMewTransform_Text_0:
	.string "Green: Alright we made it to the end,\n"
	.string "good job Ditto!$"

GreenMewTransform_Text_1:
	.string "Dittodii!$"
