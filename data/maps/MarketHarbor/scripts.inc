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
	msgbox harborFerryman_Text_0
	waitmessage
	release
	end


harborTourist_Text_0:
	.string "I'm currently visiting Hoenn with my\n"
	.string "girlfriend. We've lived in Alola for our\l"
	.string "whole lives, but decided recently to\l"
	.string "start travelling the world.$"

harborTourist_Text_1:
	.string "Have you visited any other regions?$"

harborForeman_Text_0:
	.string "The ship experienced some technical\n"
	.string "difficulties during the last trip to\l"
	.string "Hoenn from Alola.$"

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
	.string "Alola! We're currently conducting\n"
	.string "maintenance work for the ship. Come\l"
	.string "back later!$"
