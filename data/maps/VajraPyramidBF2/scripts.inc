VajraPyramidBF2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VajraPyramidBF2_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

VajraPyramidBF2_MapScripts_MAP_SCRIPT_ON_LOAD:
	call VajraPyramidBF1_Onload
	return


VajraPyramidBF1_Onload::
	call_if_eq VAR_VAJRA_PYRAMID_BF2_STATE, 1, removeFirstBarrier
	call_if_eq VAR_VAJRA_PYRAMID_BF2_STATE, 2, removeBothBarriers
	return


removeFirstBarrier::
	setmetatile 20, 25, METATILE_VajraPyramid_PyramidDoorBotLeft, TRUE
	setmetatile 21, 25, METATILE_VajraPyramid_PyramidDoorBot, FALSE
	setmetatile 22, 25, METATILE_VajraPyramid_PyramidDoorBotRight, TRUE
	setmetatile 20, 24, METATILE_VajraPyramid_PyramidDoorMidLeft, TRUE
	setmetatile 21, 24, METATILE_VajraPyramid_PyramidDoorMid, FALSE
	setmetatile 22, 24, METATILE_VajraPyramid_PyramidDoorMidRight, TRUE
	setmetatile 20, 23, METATILE_VajraPyramid_PyramidDoorTopLeft, TRUE
	setmetatile 21, 23, METATILE_VajraPyramid_PyramidDoorTop, FALSE
	setmetatile 22, 23, METATILE_VajraPyramid_PyramidDoorTopRight, TRUE
	return


removeBothBarriers::
	setmetatile 20, 25, METATILE_VajraPyramid_PyramidDoorBotLeft, TRUE
	setmetatile 21, 25, METATILE_VajraPyramid_PyramidDoorBot, FALSE
	setmetatile 22, 25, METATILE_VajraPyramid_PyramidDoorBotRight, TRUE
	setmetatile 20, 24, METATILE_VajraPyramid_PyramidDoorMidLeft, TRUE
	setmetatile 21, 24, METATILE_VajraPyramid_PyramidDoorMid, FALSE
	setmetatile 22, 24, METATILE_VajraPyramid_PyramidDoorMidRight, TRUE
	setmetatile 20, 23, METATILE_VajraPyramid_PyramidDoorTopLeft, TRUE
	setmetatile 21, 23, METATILE_VajraPyramid_PyramidDoorTop, FALSE
	setmetatile 22, 23, METATILE_VajraPyramid_PyramidDoorTopRight, TRUE
	setmetatile 20, 16, METATILE_VajraPyramid_PyramidDoorBotLeft, TRUE
	setmetatile 21, 16, METATILE_VajraPyramid_PyramidDoorBot, FALSE
	setmetatile 22, 16, METATILE_VajraPyramid_PyramidDoorBotRight, TRUE
	setmetatile 20, 15, METATILE_VajraPyramid_PyramidDoorMidLeft, TRUE
	setmetatile 21, 15, METATILE_VajraPyramid_PyramidDoorMid, FALSE
	setmetatile 22, 15, METATILE_VajraPyramid_PyramidDoorMidRight, TRUE
	setmetatile 20, 14, METATILE_VajraPyramid_PyramidDoorTopLeft, TRUE
	setmetatile 21, 14, METATILE_VajraPyramid_PyramidDoorTop, FALSE
	setmetatile 22, 14, METATILE_VajraPyramid_PyramidDoorTopRight, TRUE
	return


weightSign::
	lock
	msgbox weightSign_Text_0
	waitmessage
	release
	end


weightStatue1::
	lock
	msgbox weightStatue1_Text_0
	release
	end


weightStatue2::
	lock
	msgbox weightStatue2_Text_0
	release
	end


weightStatue3::
	lock
	msgbox weightStatue3_Text_0
	release
	end


weightStatuePlayer::
	goto_if_set FLAG_WEIGHT_PUZZLE_SOLVED, weightStatuePlayer_2
	lock
	bufferleadmonspeciesname STR_VAR_1
	msgbox weightStatuePlayer_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq weightStatuePlayer_5
weightStatuePlayer_4:
	release
	end

weightStatuePlayer_2:
	msgbox weightStatuePlayer_Text_0, MSGBOX_AUTOCLOSE
	end

weightStatuePlayer_5:
	special getPartyLeadMonWeight
	compare VAR_RESULT, 100
	goto_if_gt weightStatuePlayer_9
weightStatuePlayer_8:
	delay 60
	msgbox weightStatuePlayer_Text_3
	goto weightStatuePlayer_4

weightStatuePlayer_7:
	playse SE_PIN
	waitse
	delay 30
	setflag FLAG_WEIGHT_PUZZLE_SOLVED
	msgbox weightStatuePlayer_Text_2
	goto_if_set FLAG_WEIGHT_PUZZLE_SOLVED, weightStatuePlayer_13
	goto weightStatuePlayer_4

weightStatuePlayer_9:
	compare VAR_RESULT, 202
	goto_if_le weightStatuePlayer_7
	goto weightStatuePlayer_8

weightStatuePlayer_12:
	goto firstTwoPuzzlesCleared
	goto weightStatuePlayer_4

weightStatuePlayer_13:
	goto_if_set FLAG_HEIGHT_PUZZLE_SOLVED, weightStatuePlayer_12
	goto weightStatuePlayer_4


firstTwoPuzzlesCleared::
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 32
	setvar VAR_0x8007, 2
	special ShakeCamera
	waitstate
	setmetatile 20, 25, METATILE_VajraPyramid_PyramidDoorBotLeft, TRUE
	setmetatile 21, 25, METATILE_VajraPyramid_PyramidDoorBot, FALSE
	setmetatile 22, 25, METATILE_VajraPyramid_PyramidDoorBotRight, TRUE
	setmetatile 20, 24, METATILE_VajraPyramid_PyramidDoorMidLeft, TRUE
	setmetatile 21, 24, METATILE_VajraPyramid_PyramidDoorMid, FALSE
	setmetatile 22, 24, METATILE_VajraPyramid_PyramidDoorMidRight, TRUE
	setmetatile 20, 23, METATILE_VajraPyramid_PyramidDoorTopLeft, TRUE
	setmetatile 21, 23, METATILE_VajraPyramid_PyramidDoorTop, FALSE
	setmetatile 22, 23, METATILE_VajraPyramid_PyramidDoorTopRight, TRUE
	setvar VAR_VAJRA_PYRAMID_BF2_STATE, 1
	playse SE_EXIT
	special DrawWholeMapView
	waitse
	msgbox firstTwoPuzzlesCleared_Text_0
	release
	end


heightSign::
	lock
	msgbox heightSign_Text_0
	release
	end


heightStatue1::
	lock
	msgbox heightStatue1_Text_0
	release
	end


heightStatue2::
	lock
	msgbox heightStatue2_Text_0
	release
	end


heightStatue3::
	lock
	msgbox heightStatue3_Text_0
	release
	end


heightStatuePlayer::
	goto_if_set FLAG_HEIGHT_PUZZLE_SOLVED, heightStatuePlayer_2
	lock
	bufferleadmonspeciesname STR_VAR_1
	msgbox heightStatuePlayer_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq heightStatuePlayer_5
heightStatuePlayer_4:
	release
	end

heightStatuePlayer_2:
	msgbox weightStatuePlayer_Text_0, MSGBOX_AUTOCLOSE
	end

heightStatuePlayer_5:
	special getPartyLeadMonHeight
	compare VAR_RESULT, 0
	goto_if_ge heightStatuePlayer_9
heightStatuePlayer_8:
	delay 60
	msgbox heightStatuePlayer_Text_2
	goto heightStatuePlayer_4

heightStatuePlayer_7:
	playse SE_PIN
	waitse
	delay 30
	setflag FLAG_HEIGHT_PUZZLE_SOLVED
	msgbox heightStatuePlayer_Text_1
	goto_if_set FLAG_WEIGHT_PUZZLE_SOLVED, heightStatuePlayer_13
	goto heightStatuePlayer_4

heightStatuePlayer_9:
	compare VAR_RESULT, 10
	goto_if_lt heightStatuePlayer_7
	goto heightStatuePlayer_8

heightStatuePlayer_12:
	goto firstTwoPuzzlesCleared
	goto heightStatuePlayer_4

heightStatuePlayer_13:
	goto_if_set FLAG_HEIGHT_PUZZLE_SOLVED, heightStatuePlayer_12
	goto heightStatuePlayer_4


vaseRoomSign::
	lock
	msgbox vaseRoomSign_Text_0
	release
	end


correctVase::
	lock
	msgbox correctVase_Text_0
	msgbox correctVase_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq correctVase_2
correctVase_1:
	release
	end

correctVase_2:
	playse SE_PIN
	waitse
	delay 30
	goto secondPuzzleClearedBf2
	goto correctVase_1


secondPuzzleClearedBf2::
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 32
	setvar VAR_0x8007, 2
	special ShakeCamera
	waitstate
	setmetatile 20, 16, METATILE_VajraPyramid_PyramidDoorBotLeft, TRUE
	setmetatile 21, 16, METATILE_VajraPyramid_PyramidDoorBot, FALSE
	setmetatile 22, 16, METATILE_VajraPyramid_PyramidDoorBotRight, TRUE
	setmetatile 20, 15, METATILE_VajraPyramid_PyramidDoorMidLeft, TRUE
	setmetatile 21, 15, METATILE_VajraPyramid_PyramidDoorMid, FALSE
	setmetatile 22, 15, METATILE_VajraPyramid_PyramidDoorMidRight, TRUE
	setmetatile 20, 14, METATILE_VajraPyramid_PyramidDoorTopLeft, TRUE
	setmetatile 21, 14, METATILE_VajraPyramid_PyramidDoorTop, FALSE
	setmetatile 22, 14, METATILE_VajraPyramid_PyramidDoorTopRight, TRUE
	setvar VAR_VAJRA_PYRAMID_BF2_STATE, 2
	playse SE_EXIT
	special DrawWholeMapView
	waitse
	msgbox secondPuzzleClearedBf2_Text_0
	release
	end


BrandonF2::
	lock
	faceplayer
	msgbox BrandonF2_Text_0
	msgbox BrandonF2_Text_1
	release
	end


BrandonSign::
	msgbox BrandonSign_Text_0, MSGBOX_SIGN
	end


weightSign_Text_0:
	.string "Within this chamber, balance reigns\n"
	.string "supreme, Three guardians stand, each a\l"
	.string "weighty theme. From light as a feather\l"
	.string "to heavy as stone, Make it four\l"
	.string "guardians with one your own.$"

weightStatue1_Text_0:
	.string "Yamask: A gentle breeze could lift me\n"
	.string "off the ground. Among us four, I am the\l"
	.string "featherweight champion.$"

weightStatue2_Text_0:
	.string "Venusaur: Not quite a stone but not a\n"
	.string "feather either. I stand between the\l"
	.string "lightest and the heavy.$"

weightStatue3_Text_0:
	.string "Tyranitar: A mountain's strength, a\n"
	.string "boulder's might. Among us, I weigh the\l"
	.string "most and not even the mightiest could\l"
	.string "take me to skies.$"

weightStatuePlayer_Text_0:
	.string "This puzzle has already been solved.$"

weightStatuePlayer_Text_1:
	.string "It seems to be an empty weight that\n"
	.string "awaits something, place {STR_VAR_1}\l"
	.string "to it?$"

weightStatuePlayer_Text_2:
	.string "It seems {STR_VAR_1} weighted the\n"
	.string "correct amount!$"

weightStatuePlayer_Text_3:
	.string "...Nothing seems to have happened.\n"
	.string "Perhaps the weight was incorrect?$"

firstTwoPuzzlesCleared_Text_0:
	.string "The first gate seems to have opened..!$"

heightSign_Text_0:
	.string "In this hall of towering grace, Four\n"
	.string "sentinels stand, each a different face.\l"
	.string "From the shortest that crouches to the\l"
	.string "tallest that soars, Match your\l"
	.string "Partner's height to each of our own.$"

heightStatue1_Text_0:
	.string "Primeape: Not the tallest, nor the\n"
	.string "smallest, I'm in between. A modest\l"
	.string "height is where I'm seen.$"

heightStatue2_Text_0:
	.string "Ursaring: Taller than some but not the\n"
	.string "tallest of all. I look down but still\l"
	.string "have one above all.$"

heightStatue3_Text_0:
	.string "Drampa: A towering presence, I stand\n"
	.string "above the rest. Among us, I reach the\l"
	.string "sky, the tallest and the best.$"

heightStatuePlayer_Text_0:
	.string "It seems to be an empty pedastal that\n"
	.string "awaits something, place {STR_VAR_1}\l"
	.string "to it?$"

heightStatuePlayer_Text_1:
	.string "It seems {STR_VAR_1} was of correct\n"
	.string "height!$"

heightStatuePlayer_Text_2:
	.string "...Nothing seems to have happened.\n"
	.string "Perhaps the height was incorrect?$"

vaseRoomSign_Text_0:
	.string "In this chamber of secrets, where\n"
	.string "vessels reside, One holds the key, while\l"
	.string "others just hide. A symbol of wisdom, a\l"
	.string "mark of the wise, Find the vase that\l"
	.string "holds no disguise.$"

correctVase_Text_0:
	.string "Inside the vase is...$"

correctVase_Text_1:
	.string "A tooth of Krokorok, touch it?$"

secondPuzzleClearedBf2_Text_0:
	.string "The second gate seems to have opened..!$"

BrandonF2_Text_0:
	.string "Brandon: Hey {PLAYER}, found your\n"
	.string "way here already? I found a side\l"
	.string "entrance, but it seems that the way\l"
	.string "forward is blocked by those red gates.$"

BrandonF2_Text_1:
	.string "I take it you solved the previous room?\n"
	.string "Would you mind handling the room on the\l"
	.string "other side while I solve this one?$"

BrandonSign_Text_0:
	.string "It seems to be filled with letters from\n"
	.string "language you don't understand, better\l"
	.string "leave it to Brandon.$"
