VajraPyramidBF3_MapScripts::
	.byte 0


gengar::
	lock
	faceplayer
	msgbox gengar_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq gengar_2
gengar_1:
	release
	end

gengar_2:
	applymovement 2, gengarmoveaside
	waitmovement 2
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, playermovetrialup
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement 2, gengarmoveback
	waitmovement 2
	goto gengar_1


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
	lock
	faceplayer
	msgbox ghosttrainer1_Text_0
	trainerbattle_no_intro TRAINER_VAJRA_CHALLENGE_1, ghosttrainer1_Text_1
	release
	end


ghosttrainer2::
	return


ghosttrainer3::
	return


removeWall1::
	return


removeWall2::
	return


removeWall3::
	return


gengar_Text_0:
	.string "Start the gauntlet?$"

ghosttrainer1_Text_0:
	.string "woo$"

ghosttrainer1_Text_1:
	.string "Woop$"
