VajraPyramidF1_MapScripts::
	.byte 0


BrandonVajraPyramid1F::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PYRAMID_SILVER, BrandonVajraPyramid1F_2
	msgbox BrandonVajraPyramid1F_Text_2
	msgbox BrandonVajraPyramid1F_Text_3
BrandonVajraPyramid1F_1:
	msgbox BrandonVajraPyramid1F_Text_4
	msgbox BrandonVajraPyramid1F_Text_5
	msgbox BrandonVajraPyramid1F_Text_6
	msgbox BrandonVajraPyramid1F_Text_7
	waitmessage
	startquest QUEST_8
	waitmessage
	msgbox BrandonVajraPyramid1F_Text_8
	waitmessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_VAJRAPYRAMID_F1_BRANDON
	removeobject 1
	waitse
	fadescreen FADE_FROM_BLACK
	release
	end

BrandonVajraPyramid1F_2:
	msgbox BrandonVajraPyramid1F_Text_0
	msgbox BrandonVajraPyramid1F_Text_1
	goto BrandonVajraPyramid1F_1


BrandonVajraPyramid1F_Text_0:
	.string "Oh, hello {PLAYER}, are you perhaps\n"
	.string "interested in archaeology too, or\l"
	.string "hungry for a battle after our last\l"
	.string "clash?$"

BrandonVajraPyramid1F_Text_1:
	.string "Or... Perhaps the secrets of this\n"
	.string "pyramid caught your interest?$"

BrandonVajraPyramid1F_Text_2:
	.string "Another one eh? Hello trainer. Are you\n"
	.string "here to seek the secrets and riches of\l"
	.string "the pyramid?$"

BrandonVajraPyramid1F_Text_3:
	.string "My name is Brandon, some folks refer to\n"
	.string "me as the Pyramid King.$"

BrandonVajraPyramid1F_Text_4:
	.string "I was tasked to investigate the lower\n"
	.string "levels of this pyramid for the Battle\l"
	.string "Frontier commitee, they are interested\l"
	.string "in spicing up the Battle Pyramid with\l"
	.string "new gimmicks.$"

BrandonVajraPyramid1F_Text_5:
	.string "I care little for the paperwork and\n"
	.string "documentation side of the job. I'm in\l"
	.string "this for the thrill of exploration, I'm\l"
	.string "sure you feel the same.$"

BrandonVajraPyramid1F_Text_6:
	.string "This place seems to attract all sorts\n"
	.string "of thrillseekers, but many have been\l"
	.string "repelled by the traps laid throughout\l"
	.string "the pyramid.$"

BrandonVajraPyramid1F_Text_7:
	.string "Say why don't we team up for this one?\n"
	.string "Let's see what we can find and later\l"
	.string "share our findings. I will circle around\l"
	.string "the pyramid and look for hidden\l"
	.string "entrances, while you take the ladder\l"
	.string "down here and see what you can find.$"

BrandonVajraPyramid1F_Text_8:
	.string "Good luck in your search!$"
