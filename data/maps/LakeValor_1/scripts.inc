LakeValor_1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, return_to_reality
	.byte 0

return_to_reality::
	map_script_2 VAR_LAKE_OF_VALOR_STATE, 1, triggerThanks
	.2byte 0


anabelSwapflag::
	msgbox anabelSwapflag_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq anabelSwapflag_1
	clearflag FLAG_LAKE_OF_VALOR
	return

anabelSwapflag_1:
	setflag FLAG_LAKE_OF_VALOR
	return


triggerThanks::
	lockall
	delay 30
	msgbox triggerThanks_Text_0
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, confusedPlayer
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 60
	msgbox triggerThanks_Text_1
	delay 120
	msgbox triggerThanks_Text_2
	giveitem ITEM_GRASSIUM_Z
	setvar VAR_LAKE_OF_VALOR_STATE, 2
	releaseall
	end


confusedPlayer:
	emote_question_mark
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	delay_16
	step_end

anabelSwapflag_Text_0:
	.string "Toggle flag?$"

triggerThanks_Text_0:
	.string "T--nk y-u...$"

triggerThanks_Text_1:
	.string "...The voice fades away. It seems like\n"
	.string "the attack was an illusion, a memory\l"
	.string "perhaps?$"

triggerThanks_Text_2:
	.string "There seems to be something in front of\n"
	.string "you.$"
