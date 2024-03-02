MarketHarbor_MapScripts::
	.byte 0


harborTourist::
	lock
	faceplayer
	msgbox harborTourist_Text_0
	msgbox harborTourist_Text_1
	waitmessage
	release
	end


harborForeman::
	lock
	faceplayer
	msgbox harborForeman_Text_0
	msgbox harborForeman_Text_1
	waitmessage
	release
	end


harborResearcher::
	lock
	faceplayer
	msgbox harborResearcher_Text_0
	waitmessage
	release
	end


harborFerryman::
	lock
	faceplayer
	compare VAR_JOHTO_INTRODUCTION_STATE, 0
	goto_if_eq harborFerryman_2
harborFerryman_1:
	compare VAR_JOHTO_INTRODUCTION_STATE, 1
	goto_if_eq harborFerryman_5
harborFerryman_4:
	release
	end

harborFerryman_2:
	msgbox harborFerryman_Text_0
	waitmessage
	goto harborFerryman_1

harborFerryman_5:
	msgbox harborFerryman_Text_1
	msgbox harborFerryman_Text_2
	msgbox harborFerryman_Text_3
	goto harborFerryman_4


harborTourist_Text_0:
	.string "I'm currently visiting Hoenn with my\n"
	.string "girlfriend. We've lived in Johto for our\l"
	.string "whole lives, but decided recently to\l"
	.string "start travelling the world.$"

harborTourist_Text_1:
	.string "Have you visited any other regions?$"

harborForeman_Text_0:
	.string "The ship experienced some technical\n"
	.string "difficulties during the last trip to\l"
	.string "Hoenn from Johto.$"

harborForeman_Text_1:
	.string "We're making sure that everything is\n"
	.string "functional for the return trip.$"

harborResearcher_Text_0:
	.string "I'm working on my thesis about Orange\n"
	.string "Archipelago and its native Pokémon\l"
	.string "species for Celadon university. Did you\l"
	.string "know there exists an island where all\l"
	.string "local species have turned pink?$"

harborFerryman_Text_0:
	.string "Hello! We're currently conducting\n"
	.string "maintenance work for the ship. Come\l"
	.string "back a bit later!$"

harborFerryman_Text_1:
	.string "Hello! We're now hosting a banquet at\n"
	.string "the S.S Anne before returning to Johto.\l"
	.string "May I see your ticket?$"

harborFerryman_Text_2:
	.string "{PLAYER} flashed the S.S Ticket!$"

harborFerryman_Text_3:
	.string "Great! Welcome aboard!$"
