LakeValor2_Cave_MapScripts::
	.byte 0


gCommanderSaturn::
	lockall
	msgbox gCommanderSaturn_Text_0
	waitmessage
	applymovement 1, saturnMov1
	waitmovement 1
	delay 60
	msgbox gCommanderSaturn_Text_1
	msgbox gCommanderSaturn_Text_2
	msgbox gCommanderSaturn_Text_3
	trainerbattle_no_intro TRAINER_GSATURN_1, gCommanderSaturn_Text_4
	msgbox gCommanderSaturn_Text_5
	msgbox gCommanderSaturn_Text_6
	msgbox gCommanderSaturn_Text_7
	waitmessage
	clearflag FLAG_LAKE_OF_VALOR
	setvar VAR_LAKE_OF_VALOR_STATE, 1
	removeobject 1
	warpsilent MAP_LAKE_VALOR_1, 52, 49
	releaseall
	end


saturnMov1:
	emote_exclamation_mark
	face_down
	step_end

gCommanderSaturn_Text_0:
	.string "The mission is proceeding without a\n"
	.string "hitch. The boss should be pleased.\l"
	.string "Everything is for everyone, and for the\l"
	.string "good of Team Galactic!$"

gCommanderSaturn_Text_1:
	.string "Who are you, child?$"

gCommanderSaturn_Text_2:
	.string "If you're here to meddle in affairs of\n"
	.string "Team Galactic, then you shall be\l"
	.string "crushed!$"

gCommanderSaturn_Text_3:
	.string "Even the very thought of opposition\n"
	.string "will not be tolerated!$"

gCommanderSaturn_Text_4:
	.string "You, my friend, are tough! I can see why\n"
	.string "you defy us so...$"

gCommanderSaturn_Text_5:
	.string "Gah, Even I, a Commander, only managed\n"
	.string "to buy us time?$"

gCommanderSaturn_Text_6:
	.string "But that's fine.$"

gCommanderSaturn_Text_7:
	.string "A child like you will never be able to\n"
	.string "stem the flow of time!$"
