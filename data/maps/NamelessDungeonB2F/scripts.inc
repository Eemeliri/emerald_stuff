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
	seteventmon SPECIES_MEWTWO, 80
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
	returnqueststate QUEST_2
	goto_if_eq VAR_RESULT, 1, startLegendaryQuestMewtwo
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_4
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


startLegendaryQuestMewtwo::
	startquest QUEST_2
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_2, SUB_QUEST_4
	release
	end


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
	addobject 5
	setobjectxy 5, 52, 23
	delay 30
	removeobject 5
	setflag FLAG_HIDE_DITTO
	playse SE_PIN
	applymovement 2, greenNoticePlayer
	waitmovement 2
	applymovement OBJ_EVENT_ID_CAMERA, panBackFromGreen
	waitmovement OBJ_EVENT_ID_CAMERA
	delay 60
	special RemoveCameraObject
	setvar VAR_NAMELESS_DUNGEON_GREEN_STATE, 1
	releaseall
	end


challengeGreenFromLeft::
	lock
	faceplayer
	msgbox challengeGreenFromLeft_Text_0
	msgbox challengeGreenFromLeft_Text_1
	msgbox challengeGreenFromLeft_Text_2
	waitmessage
	applymovement 2, faceGreenUp
	waitmovement 2
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, panCameraToMewtwo
	msgbox challengeGreenFromLeft_Text_3
	delay 60
	applymovement OBJ_EVENT_ID_CAMERA, panCameraBackFromMewtwo
	waitmovement OBJ_EVENT_ID_CAMERA
	delay 20
	applymovement 2, GreenFacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, facePlayerRightGreen
	special RemoveCameraObject
	msgbox challengeGreenFromLeft_Text_4
	waitmessage
	msgbox challengeGreenFromLeft_Text_5
	trainerbattle_no_intro TRAINER_GREEN_MEWTWO, challengeGreenFromLeft_Text_6
	msgbox challengeGreenFromLeft_Text_7
	msgbox challengeGreenFromLeft_Text_8
	msgbox challengeGreenFromLeft_Text_9
	waitmessage
	giveitem ITEM_MEWTWONITE_X
	waitmessage
	giveitem ITEM_MEWTWONITE_Y
	waitmessage
	msgbox challengeGreenFromLeft_Text_10
	waitmessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GREEN
	removeobject 2
	delay 60
	fadescreen FADE_FROM_BLACK
	delay 20
	release
	end


panCameraToMewtwo:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

panCameraBackFromMewtwo:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

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

faceGreenUp:
	face_up
	step_end

facePlayerUpGreen:
	face_up
	step_end

facePlayerRightGreen:
	face_right
	step_end

GreenFacePlayer:
	face_player
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
	.string "???: Alright we made it to the end, good\n"
	.string "job Ditto!$"

GreenMewTransform_Text_1:
	.string "Dittodii!$"

challengeGreenFromLeft_Text_0:
	.string "???: Since you've made it this far, I\n"
	.string "assume you must be the champion of\l"
	.string "Hoenn.$"

challengeGreenFromLeft_Text_1:
	.string "???: It's so nice to finally meet you in\n"
	.string "person! My name is Green!$"

challengeGreenFromLeft_Text_2:
	.string "Green: I'm currently travelling across\n"
	.string "regions to fill up the Pokédex for\l"
	.string "Professor Oak and to train my partner\l"
	.string "Pokémon.$"

challengeGreenFromLeft_Text_3:
	.string "Green: See that strong Pokémon up\n"
	.string "there? That's Mewtwo, an artificial\l"
	.string "species created solely for battles. It\l"
	.string "has been resting in this cave for a very\l"
	.string "long time.$"

challengeGreenFromLeft_Text_4:
	.string "Green: How about we fight over who gets\n"
	.string "to catch it? I'll even throw you a little\l"
	.string "bonus if you manage to beat me!$"

challengeGreenFromLeft_Text_5:
	.string "Green: Ready? Don't except an easy\n"
	.string "fight!$"

challengeGreenFromLeft_Text_6:
	.string "Incredible! You are just as good as I\n"
	.string "had hoped.$"

challengeGreenFromLeft_Text_7:
	.string "Green: Even though I lost I don't feel\n"
	.string "sad or angry, in fact I feel happy to\l"
	.string "have battled you!$"

challengeGreenFromLeft_Text_8:
	.string "Green: As promised, you will get to\n"
	.string "catch Mewtwo, although if you fail I will\l"
	.string "come to pick up your pieces.$"

challengeGreenFromLeft_Text_9:
	.string "Green: And that added bonus I was\n"
	.string "speaking of? Here you go!$"

challengeGreenFromLeft_Text_10:
	.string "Green: I'm going to head off into\n"
	.string "another region now, perhaps Alola? I\l"
	.string "might swing by the Pokémon World\l"
	.string "Tournament while I'm still here, hope to\l"
	.string "see you in there for a rematch.$"
