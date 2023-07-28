VajraPyramidBF1_MapScripts::
	.byte 0


hideBF1StairsPyramid::
	return


PyramidBF1Sign::
	msgbox PyramidBF1Sign_Text_0, MSGBOX_SIGN
	end


stepOnBF1Switch::
	lock
	playse SE_CLICK
	setmetatile 38, 3, METATILE_VajraPyramid_PyramidLadderBottom, FALSE
	setmetatile 38, 2, METATILE_VajraPyramid_PyramidLadderTop, TRUE
	setmetatile 38, 15, METATILE_pyramidpuzzles_pyramidButtonPressed, FALSE
	special DrawWholeMapView
	setvar VAR_TEMP_0, 1
	waitse
	release
	end


PyramidBF1Sign_Text_0:
	.string "When the young ruler was still but a\n"
	.string "boy, he would sneak into town during\l"
	.string "busy nights. However even the busy\l"
	.string "markets were filled with people who\l"
	.string "would seek to harm him if he were\l"
	.string "noticed.$"
