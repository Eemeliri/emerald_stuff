BrawlyDojo_MapScripts::
	.byte 0


megaKickTrainer::
	lock
	msgbox megaKickTrainer_Text_0
	release
	end


megaPunchTrainer::
	lock
	msgbox megaPunchTrainer_Text_0
	release
	end


DojoTourist::
	lock
	faceplayer
	msgbox DojoTourist_Text_0
	release
	end


DojoTrainee::
	lock
	faceplayer
	msgbox DojoTrainee_Text_0
	release
	end


DojoTeacher::
	lock
	faceplayer
	msgbox DojoTeacher_Text_0
	release
	end


dojoKubfu::
	bufferspeciesname 0, SPECIES_KUBFU
	lock
	faceplayer
	playmoncry SPECIES_KUBFU, CRY_MODE_NORMAL
	msgbox dojoKubfu_Text_0
	waitmoncry
	release
	end


dojoKubfuGentleman::
	lock
	faceplayer
	msgbox dojoKubfuGentleman_Text_0
	goto_if_set FLAG_BADGE02_GET, dojoKubfuGentleman_2
	msgbox dojoKubfuGentleman_Text_6
	release
	end

dojoKubfuGentleman_2:
	msgbox dojoKubfuGentleman_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq dojoKubfuGentleman_4
	msgbox dojoKubfuGentleman_Text_5
	release
	end

dojoKubfuGentleman_4:
	msgbox dojoKubfuGentleman_Text_2
	playfanfare MUS_OBTAIN_ITEM
	givecustommon SPECIES_KUBFU, 5, ITEM_NONE, ITEM_CHERISH_BALL
	removeobject 7
	showmonpic SPECIES_KUBFU, 10, 3
	bufferspeciesname STR_VAR_1, SPECIES_KUBFU
	msgbox dojoKubfuGentleman_Text_3
	waitfanfare
	waitmessage
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq dojoKubfuGentleman_8
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq dojoKubfuGentleman_13
dojoKubfuGentleman_7:
	hidemonpic
	msgbox dojoKubfuGentleman_Text_4
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject 6
	delay 50
	fadescreen FADE_FROM_BLACK
	release
	end

dojoKubfuGentleman_8:
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq dojoKubfuGentleman_11
	goto dojoKubfuGentleman_7

dojoKubfuGentleman_11:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto dojoKubfuGentleman_7

dojoKubfuGentleman_13:
	call Common_EventScript_NameReceivedBoxMon
	goto dojoKubfuGentleman_7


megaKickTrainer_Text_0:
	.string "No no, you don't get it, Mega Punch is\n"
	.string "the superior move!$"

megaPunchTrainer_Text_0:
	.string "Fool! Everyone knows Mega Kick is the\n"
	.string "true path to power!$"

DojoTourist_Text_0:
	.string "The doors behind me lead to training\n"
	.string "room and battle arena. I hear the arena\l"
	.string "is still under construction though.$"

DojoTrainee_Text_0:
	.string "If you want to grow stronger, you\n"
	.string "should visit the training room.$"

DojoTeacher_Text_0:
	.string "Ahead is the practice room for\n"
	.string "students, take care not to disturb\l"
	.string "them.$"

dojoKubfu_Text_0:
	.string "Kub?$"

dojoKubfuGentleman_Text_0:
	.string "I came here looking for someone strong\n"
	.string "enough to take care of my Kubfu. I am\l"
	.string "not capable of giving it the training it\l"
	.string "requires, such lifestyle is past me now.$"

dojoKubfuGentleman_Text_1:
	.string "You! You have the badge from Brawly\n"
	.string "don't you?! Please, take Kubfu and show\l"
	.string "it the world. Surely a trainer of your\l"
	.string "caliber is capable of giving it the\l"
	.string "training it needs?$"

dojoKubfuGentleman_Text_2:
	.string "Thank you! Please take good care of\n"
	.string "Kubfu!$"

dojoKubfuGentleman_Text_3:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from the gentleman!$"

dojoKubfuGentleman_Text_4:
	.string "Take care now.$"

dojoKubfuGentleman_Text_5:
	.string "Oh... I guess you are too busy for such\n"
	.string "Pokémon...$"

dojoKubfuGentleman_Text_6:
	.string "Nobody here seems to have the\n"
	.string "experience it takes... Perhaps we will\l"
	.string "wait until someone of high caliber\l"
	.string "arrives...$"
