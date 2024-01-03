VajraDesert_MapScripts::
	.byte 0


RuinManiacNearPyramidStairs::
	lock
	applymovement 17, ruinManiacExcitedJump
	waitmovement 17
	msgbox RuinManiacNearPyramidStairs_Text_0
	waitmessage
	release
	end


ruinManiacExcitedJump:
	jump_in_place_up
	delay_16
	jump_in_place_up
	delay_16
	step_end

PicnickerNearTunnelExit::
	lock
	faceplayer
	msgbox PicnickerNearTunnelExit_Text_0
	waitmessage
	release
	end


SailorNearDesertTown::
	lock
	faceplayer
	msgbox SailorNearDesertTown_Text_0
	waitmessage
	release
	end


HikerAtVajraDesertEntrance::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_FRESH_WATER, HikerAtVajraDesertEntrance_2
	msgbox HikerAtVajraDesertEntrance_Text_1
	giveitem ITEM_FRESH_WATER
	setflag FLAG_RECEIVED_FRESH_WATER
	msgbox HikerAtVajraDesertEntrance_Text_0
HikerAtVajraDesertEntrance_1:
	waitmessage
	release
	end

HikerAtVajraDesertEntrance_2:
	msgbox HikerAtVajraDesertEntrance_Text_0
	goto HikerAtVajraDesertEntrance_1


VajraDesertTownSign::
	msgbox VajraDesertTownSign_Text_0, MSGBOX_SIGN
	end


VajraDesertTunnelSign::
	msgbox VajraDesertTunnelSign_Text_0, MSGBOX_SIGN
	end


VajraDesertPyramidSign::
	msgbox VajraDesertPyramidSign_Text_0, MSGBOX_SIGN
	end


PsychicTrainerVajraDesert::
	return


BattleGirlSouthVajraDesert::
	return


SandileDesert::
	lock
	faceplayer
	playmoncry SPECIES_SANDILE, CRY_MODE_NORMAL
	msgbox SandileDesert_Text_0
	waitmoncry
	release
	end


CrustleDesert::
	lock
	faceplayer
	playmoncry SPECIES_CRUSTLE, CRY_MODE_NORMAL
	msgbox CrustleDesert_Text_0
	waitmoncry
	release
	end


RuinManiacNearPyramidStairs_Text_0:
	.string "Finally I found a route past those\n"
	.string "quicksand pits, now all riches of The\l"
	.string "pyramid await!$"

PicnickerNearTunnelExit_Text_0:
	.string "You should stay clear of those\n"
	.string "quicksand pits, they will suck you in\l"
	.string "and drop you to caves below.$"

SailorNearDesertTown_Text_0:
	.string "Ahead lies the Vajra Town, you should\n"
	.string "stop by to rest after your trip through\l"
	.string "the desert!$"

HikerAtVajraDesertEntrance_Text_0:
	.string "If you are looking for a place to rest,\n"
	.string "you should head east to Vajra Village\l"
	.string "to find a Pokémon Center.$"

HikerAtVajraDesertEntrance_Text_1:
	.string "Made it past the tunnels eh? Have this\n"
	.string "to refresh your weary mind!$"

VajraDesertTownSign_Text_0:
	.string "Vajra Village, the blooming oasis of the\n"
	.string "desert.$"

VajraDesertTunnelSign_Text_0:
	.string "{RIGHT_ARROW} Vajra Village$"

VajraDesertPyramidSign_Text_0:
	.string "{UP_ARROW} Vajra Pyramid$"

SandileDesert_Text_0:
	.string "Sandii?$"

CrustleDesert_Text_0:
	.string "Crustlee?$"
