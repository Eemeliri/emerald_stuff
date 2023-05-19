LakeValor2_MapScripts::
	.byte 0


magikarps::
	lockall
	playmoncry SPECIES_MAGIKARP, CRY_MODE_FAINT
	msgbox magikarps_Text_0, MSGBOX_AUTOCLOSE
	releaseall
	end


firstTimeVista::
	lockall
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, cameraVista
	waitmovement 0
	delay 120
	applymovement OBJ_EVENT_ID_CAMERA, cameraVista2
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_LAKEOFVALOR2_VISTA, 1
	releaseall
	end


cameraVista:
	emote_exclamation_mark
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

cameraVista2:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

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


grunt_extra2::
	lockall
	faceplayer
	msgbox grunt_extra2_Text_0
	releaseall
	end


magikarps_Text_0:
	.string "A Magikarp is weakly flopping about...$"

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
	.string "We're Team Galactic! The no. 1 syndicate\n"
	.string "in the world! To defy is to defy the\l"
	.string "universe!$"

grunt_extra1_Text_0:
	.string "Even Team Galactic has no use for\n"
	.string "Magikarp! Worthless, all of them!$"

grunt_extra2_Text_0:
	.string "What do you want? You're investigating\n"
	.string "the explosion? Bah, it doesn't matter\l"
	.string "who you are. It's too late to make any\l"
	.string "difference. Things are going to get\l"
	.string "really interesting now.$"
