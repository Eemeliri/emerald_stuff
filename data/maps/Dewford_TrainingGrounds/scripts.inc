Dewford_TrainingGrounds_MapScripts::
	.byte 0


dewfordDojoMakuhita::
	bufferspeciesname 0, SPECIES_MAKUHITA
	lock
	faceplayer
	playmoncry SPECIES_MAKUHITA, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	release
	end


dewfordDojoMeditite::
	bufferspeciesname 0, SPECIES_MEDITITE
	lock
	faceplayer
	playmoncry SPECIES_MEDITITE, CRY_MODE_NORMAL
	delay 40
	waitmoncry
	release
	end


dewfordDojoBattleItemSeller::
	lock
	faceplayer
	msgbox dewfordDojoBattleItemSeller_Text_0
	pokemart powerItemsDewford
	msgbox dewfordDojoBattleItemSeller_Text_1
	release
	end


	.align 2
powerItemsDewford:
	.2byte ITEM_POWER_ANKLET
	.2byte ITEM_POWER_BAND
	.2byte ITEM_POWER_BELT
	.2byte ITEM_POWER_BRACER
	.2byte ITEM_POWER_LENS
	.2byte ITEM_POWER_WEIGHT
	.2byte ITEM_NONE

blackbeltDewfordDojo::
	lock
	faceplayer
	msgbox blackbeltDewfordDojo_Text_0
	release
	end


battlegirlDewfordDojo::
	lock
	faceplayer
	msgbox battlegirlDewfordDojo_Text_0
	release
	end


oceanmanDewfordDojo::
	lock
	msgbox oceanmanDewfordDojo_Text_0
	playmoncry SPECIES_MEDITITE, CRY_MODE_NORMAL
	msgbox oceanmanDewfordDojo_Text_1
	waitmoncry
	release
	end


veteranDewfordDojo::
	lock
	faceplayer
	msgbox veteranDewfordDojo_Text_0
	release
	end


dewfordDojoBattleItemSeller_Text_0:
	.string "Not feeling the progress? I have\n"
	.string "something that might help you if you\l"
	.string "can help me fund my training fees...$"

dewfordDojoBattleItemSeller_Text_1:
	.string "Come again!$"

blackbeltDewfordDojo_Text_0:
	.string "Makuhita and I are training in hopes of\n"
	.string "passing the gym test. Those who pass\l"
	.string "are allowed to work in Brawly's gym!$"

battlegirlDewfordDojo_Text_0:
	.string "The training never stops! Brawly says\n"
	.string "endurance is as important as strength,\l"
	.string "so I'm going to run until I faint!$"

oceanmanDewfordDojo_Text_0:
	.string "I wonder how long we would need to swim\n"
	.string "in order to reach another region...$"

oceanmanDewfordDojo_Text_1:
	.string "Medii...$"

veteranDewfordDojo_Text_0:
	.string "Our dojo is renowned for its training\n"
	.string "methods. If you are interested in\l"
	.string "strengthening yourself or your\l"
	.string "Pokémon, you have come to the right\l"
	.string "place.$"
