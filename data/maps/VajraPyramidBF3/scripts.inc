VajraPyramidBF3_MapScripts::
	.byte 0


gengar::
	lock
	faceplayer
	goto_if_set FLAG_DAILY_VAJRA_PYRAMID_CHALLENGE, gengar_2
	msgbox gengar_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq gengar_5
gengar_4:
	release
	end

gengar_2:
	msgbox gengar_Text_0
	release
	end

gengar_5:
	closemessage
	applymovement 2, gengarmoveaside
	waitmovement 2
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, playermovetrialup
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement 2, gengarmoveback
	waitmovement 2
	setflag FLAG_DAILY_VAJRA_PYRAMID_CHALLENGE
	goto gengar_4


gengarmoveaside:
	walk_up
	walk_up
	walk_left
	face_right
	step_end

gengarmoveback:
	walk_right
	walk_down
	walk_down
	face_up
	step_end

playermovetrialup:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

brandonpyramid3f::
	return


ghosttrainer1::
	bufferspeciesname 0, SPECIES_GASTLY
	lock
	faceplayer
	goto_if_set FLAG_TEMP_10, ghosttrainer1_2
	msgbox ghosttrainer1_Text_1
	trainerbattle_no_intro TRAINER_VAJRA_CHALLENGE_1, ghosttrainer1_Text_2
	call removeWall1
	setflag FLAG_TEMP_10
	release
	end

ghosttrainer1_2:
	msgbox ghosttrainer1_Text_0
	release
	end


ghosttrainer2::
	bufferspeciesname 0, SPECIES_HAUNTER
	lock
	faceplayer
	goto_if_set FLAG_TEMP_11, ghosttrainer2_2
	msgbox ghosttrainer1_Text_1
	trainerbattle_no_intro TRAINER_VAJRA_CHALLENGE_1, ghosttrainer1_Text_2
	call removeWall2
	setflag FLAG_TEMP_11
	release
	end

ghosttrainer2_2:
	msgbox ghosttrainer1_Text_0
	release
	end


ghosttrainer3::
	bufferspeciesname 0, SPECIES_GENGAR
	lock
	faceplayer
	goto_if_set FLAG_TEMP_12, ghosttrainer3_2
	msgbox ghosttrainer1_Text_1
	trainerbattle_no_intro TRAINER_VAJRA_CHALLENGE_1, ghosttrainer1_Text_2
	call removeWall3
	setflag FLAG_TEMP_12
	release
	end

ghosttrainer3_2:
	msgbox ghosttrainer1_Text_0
	release
	end


gauntletRewardChest::
	lock
	msgbox gauntletRewardChest_Text_0
	waitmessage
	closemessage
	call openChestAfterGauntlet
	delay 60
	special pyramidGauntletRewards
	callstd STD_OBTAIN_ITEM
	special pyramidGauntletRewards
	callstd STD_OBTAIN_ITEM
	special pyramidGauntletRewards
	callstd STD_OBTAIN_ITEM
	msgbox gauntletRewardChest_Text_1
	warpspinenter MAP_VAJRA_PYRAMID_BF3, 22, 82
	release
	end


openChestAfterGauntlet::
	setmetatile 22, 21, METATILE_pyramidpuzzles_GauntletChestOpened, TRUE
	playse SE_DOOR
	special DrawWholeMapView
	waitse
	return


removeWall1::
	setmetatile 21, 59, METATILE_VajraPyramid_PyramidDoorBotLeft, TRUE
	setmetatile 22, 59, METATILE_VajraPyramid_PyramidDoorBot, FALSE
	setmetatile 23, 59, METATILE_VajraPyramid_PyramidDoorBotRight, TRUE
	setmetatile 21, 58, METATILE_VajraPyramid_PyramidDoorMidLeft, TRUE
	setmetatile 22, 58, METATILE_VajraPyramid_PyramidDoorMid, FALSE
	setmetatile 23, 58, METATILE_VajraPyramid_PyramidDoorMidRight, TRUE
	setmetatile 21, 57, METATILE_VajraPyramid_PyramidDoorTopLeft, TRUE
	setmetatile 22, 57, METATILE_VajraPyramid_PyramidDoorTop, FALSE
	setmetatile 23, 57, METATILE_VajraPyramid_PyramidDoorTopRight, TRUE
	playse SE_EXIT
	special DrawWholeMapView
	waitse
	return


removeWall2::
	setmetatile 21, 42, METATILE_VajraPyramid_PyramidDoorBotLeft, TRUE
	setmetatile 22, 42, METATILE_VajraPyramid_PyramidDoorBot, FALSE
	setmetatile 23, 42, METATILE_VajraPyramid_PyramidDoorBotRight, TRUE
	setmetatile 21, 41, METATILE_VajraPyramid_PyramidDoorMidLeft, TRUE
	setmetatile 22, 41, METATILE_VajraPyramid_PyramidDoorMid, FALSE
	setmetatile 23, 41, METATILE_VajraPyramid_PyramidDoorMidRight, TRUE
	setmetatile 21, 40, METATILE_VajraPyramid_PyramidDoorTopLeft, TRUE
	setmetatile 22, 40, METATILE_VajraPyramid_PyramidDoorTop, FALSE
	setmetatile 23, 40, METATILE_VajraPyramid_PyramidDoorTopRight, TRUE
	playse SE_EXIT
	special DrawWholeMapView
	waitse
	return


removeWall3::
	setmetatile 21, 25, METATILE_VajraPyramid_PyramidDoorBotLeft, TRUE
	setmetatile 22, 25, METATILE_VajraPyramid_PyramidDoorBot, FALSE
	setmetatile 23, 25, METATILE_VajraPyramid_PyramidDoorBotRight, TRUE
	setmetatile 21, 24, METATILE_VajraPyramid_PyramidDoorMidLeft, TRUE
	setmetatile 22, 24, METATILE_VajraPyramid_PyramidDoorMid, FALSE
	setmetatile 23, 24, METATILE_VajraPyramid_PyramidDoorMidRight, TRUE
	setmetatile 21, 23, METATILE_VajraPyramid_PyramidDoorTopLeft, TRUE
	setmetatile 22, 23, METATILE_VajraPyramid_PyramidDoorTop, FALSE
	setmetatile 23, 23, METATILE_VajraPyramid_PyramidDoorTopRight, TRUE
	playse SE_EXIT
	special DrawWholeMapView
	waitse
	return


gengar_Text_0:
	.string "Sorry pal, you've had your try for\n"
	.string "today. Come back tomorrow for more\l"
	.string "battles.$"

gengar_Text_1:
	.string "Start the gauntlet?$"

ghosttrainer1_Text_0:
	.string "Go on.$"

ghosttrainer1_Text_1:
	.string "woo$"

ghosttrainer1_Text_2:
	.string "Woop$"

gauntletRewardChest_Text_0:
	.string "As a reward for beating the gauntlet of\n"
	.string "spirits. You shall receive...$"

gauntletRewardChest_Text_1:
	.string "The spirits will be eager to face you\n"
	.string "again tomorrow.$"
