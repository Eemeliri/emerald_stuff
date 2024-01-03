GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F
	end

graniteCaveBrock::
	lock
	goto_if_set FLAG_TEMP_4, graniteCaveBrock_2
	msgbox graniteCaveBrock_Text_5
	waitmessage
	playse SE_PIN
	applymovement 3, graniteCaveBrockSurprised
	waitmovement 3
	msgbox graniteCaveBrock_Text_6
	waitmessage
	msgbox graniteCaveBrock_Text_7
	msgbox graniteCaveBrock_Text_8
	msgbox graniteCaveBrock_Text_9, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq graniteCaveBrock_5
	msgbox graniteCaveBrock_Text_4
	setflag FLAG_TEMP_4
graniteCaveBrock_4:
	release
	end

graniteCaveBrock_2:
	msgbox graniteCaveBrock_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq graniteCaveBrock_9
graniteCaveBrock_8:
	msgbox graniteCaveBrock_Text_4
	release
	end

graniteCaveBrock_5:
	goto_if_unset FLAG_BADGE02_GET, graniteCaveBrock_12
	msgbox graniteCaveBrock_Text_2
graniteCaveBrock_11:
	trainerbattle_no_intro TRAINER_GRANITECAVE_BROCK, graniteCaveBrock_Text_3
	goto graniteCaveBrockPostBattle
	goto graniteCaveBrock_4

graniteCaveBrock_9:
	goto_if_unset FLAG_BADGE02_GET, graniteCaveBrock_16
	msgbox graniteCaveBrock_Text_2
graniteCaveBrock_15:
	trainerbattle_no_intro TRAINER_GRANITECAVE_BROCK, graniteCaveBrock_Text_3
	goto graniteCaveBrockPostBattle
	goto graniteCaveBrock_8

graniteCaveBrock_12:
	msgbox graniteCaveBrock_Text_1
	goto graniteCaveBrock_11

graniteCaveBrock_16:
	msgbox graniteCaveBrock_Text_1
	goto graniteCaveBrock_15


graniteCaveBrockPostBattle::
	msgbox graniteCaveBrockPostBattle_Text_0
	msgbox graniteCaveBrockPostBattle_Text_1
	msgbox graniteCaveBrockPostBattle_Text_2
	giveegg SPECIES_GROWLITHE_HISUIAN
	msgbox graniteCaveBrockPostBattle_Text_3
	waitmessage
	fadescreen FADE_TO_BLACK
	removeobject 3
	delay 60
	fadescreen FADE_FROM_BLACK
	release
	end


graniteCaveBrockSurprised:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	face_down
	step_end

graniteCaveBrock_Text_0:
	.string "Oh hey! Had a change of mind?$"

graniteCaveBrock_Text_1:
	.string "Excelent! Don't worry I won't go all out\n"
	.string "since you're still a rookie.$"

graniteCaveBrock_Text_2:
	.string "Excelent! This should be exciting!$"

graniteCaveBrock_Text_3:
	.string "Incredible! You will go far!$"

graniteCaveBrock_Text_4:
	.string "I see, perhaps another time then?$"

graniteCaveBrock_Text_5:
	.string "???: No signs for fossils here either...$"

graniteCaveBrock_Text_6:
	.string "Ah, I didn't see you there! My name is\n"
	.string "Brock and I come from Kanto region. I am\l"
	.string "currently excavating the caves in\l"
	.string "Hoenn for fossils.$"

graniteCaveBrock_Text_7:
	.string "Brock: Unfortunately I've not found\n"
	.string "any yet...$"

graniteCaveBrock_Text_8:
	.string "Regardless, what are you doing in this\n"
	.string "place? Are you a trainer taking on the\l"
	.string "gyms?$"

graniteCaveBrock_Text_9:
	.string "If you don't mind, would you care to\n"
	.string "battle me? I haven't had a chance to\l"
	.string "battle in a while so it would be a great\l"
	.string "workout.$"

graniteCaveBrockPostBattle_Text_0:
	.string "I am surprised, you are extremely\n"
	.string "skilled for a such a fresh trainer! I\l"
	.string "enjoyed that battle immensely.$"

graniteCaveBrockPostBattle_Text_1:
	.string "I have to get back to my work now, but I\n"
	.string "hope we meet again. It would be great to\l"
	.string "fight you at full strength once you\l"
	.string "have even more experience.$"

graniteCaveBrockPostBattle_Text_2:
	.string "Before I go, I would like you to have\n"
	.string "this egg, it is for a very special\l"
	.string "Pokémon that you can't find easily\l"
	.string "anymore.$"

graniteCaveBrockPostBattle_Text_3:
	.string "And with that, I bid you farewell.$"
