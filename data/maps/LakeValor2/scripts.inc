LakeValor2_MapScripts::
	.byte 0


magikarps::
	lockall
	playmoncry SPECIES_MAGIKARP, CRY_MODE_FAINT
	msgbox magikarps_Text_0, MSGBOX_AUTOCLOSE
	releaseall
	end


anabelSwapflag2::
	lockall
	msgbox anabelSwapflag2_Text_0
	clearflag FLAG_LAKE_OF_VALOR
	warp MAP_ROUTE103, 8, 2
	releaseall
	end


gGrunt_1::
	trainerbattle_single TRAINER_GGRUNT_1, gGrunt_1_Text_0, gGrunt_1_Text_1
	msgbox gGrunt_1_Text_2, MSGBOX_AUTOCLOSE
	end


gGrunt_2::
	trainerbattle_single TRAINER_GGRUNT_2, gGrunt_2_Text_0, gGrunt_2_Text_1
	msgbox gGrunt_2_Text_2, MSGBOX_AUTOCLOSE
	end


gGrunt_3::
	trainerbattle_single TRAINER_GGRUNT_3, gGrunt_3_Text_0, gGrunt_3_Text_1
	msgbox gGrunt_3_Text_2, MSGBOX_AUTOCLOSE
	end


grunt_extra1::
	lockall
	faceplayer
	msgbox grunt_extra1_Text_0
	releaseall
	end


gCommanderSaturn::
	trainerbattle_single TRAINER_GSATURN_1, gCommanderSaturn_Text_0, gCommanderSaturn_Text_1
	msgbox gCommanderSaturn_Text_2, MSGBOX_AUTOCLOSE
	end


magikarps_Text_0:
	.string "A Magikarp is weakly flopping about...$"

anabelSwapflag2_Text_0:
	.string "flag toggling off.$"

gGrunt_1_Text_0:
	.string "Would you like to join the Magikarp and\n"
	.string "flop around in the mud?$"

gGrunt_1_Text_1:
	.string "Overwhelming!$"

gGrunt_1_Text_2:
	.string "I played you for a child, and paid a\n"
	.string "stiff price for my arrogance... However\l"
	.string "you are too late, Team Galactic has\l"
	.string "already found the island of the lake.\l"
	.string "And the Pokémon that lay in it? What do\l"
	.string "you think?$"

gGrunt_2_Text_0:
	.string "We set off the Galactic Bomb! Its blast\n"
	.string "force was phenomenal!$"

gGrunt_2_Text_1:
	.string "Your Pokémon attack with phenomenal\n"
	.string "power...$"

gGrunt_2_Text_2:
	.string "But so what? You aim to take us all on?\n"
	.string "Dream on! Team Galactic is huge in\l"
	.string "number.$"

gGrunt_3_Text_0:
	.string "I'll punish you in place of our boss for\n"
	.string "defying Team Galactic!$"

gGrunt_3_Text_1:
	.string "Grr... I took the punishment.$"

gGrunt_3_Text_2:
	.string "We're Team Galactic! The no. 1 syndicate in the world! To defy is to defy the universe!$"

grunt_extra1_Text_0:
	.string "Even Team Galactic has no use for\n"
	.string "Magikarp! Worthless, all of them!$"

gCommanderSaturn_Text_0:
	.string "todo1$"

gCommanderSaturn_Text_1:
	.string "todo2$"

gCommanderSaturn_Text_2:
	.string "I'll beat you next time$"
