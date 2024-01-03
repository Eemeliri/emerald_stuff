BrawlyDojoEVRoom_MapScripts::
	.byte 0


tiredGirlDojo::
	lock
	faceplayer
	returnqueststate QUEST_10
	switch VAR_RESULT
	case 1, tiredGirlDojo_3
	case 2, tiredGirlDojo_4
	case 4, tiredGirlDojo_5
tiredGirlDojo_1:
	release
	end

tiredGirlDojo_3:
	msgbox tiredGirlDojo_Text_0
	msgbox tiredGirlDojo_Text_1
	msgbox tiredGirlDojo_Text_2
	startquest QUEST_10
	goto tiredGirlDojo_1

tiredGirlDojo_4:
	msgbox tiredGirlDojo_Text_3
	checkpartymove MOVE_SING
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq tiredGirlDojo_7
	msgbox tiredGirlDojo_Text_4
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox tiredGirlDojo_Text_5
	msgbox tiredGirlDojo_Text_6
	giveitem ITEM_PUNCHING_GLOVE
	completequest QUEST_10
	release
	end

tiredGirlDojo_5:
	msgbox tiredGirlDojo_Text_7
	goto tiredGirlDojo_1

tiredGirlDojo_7:
	release
	end


oldLadyDojoBedroom::
	lock
	faceplayer
	msgbox oldLadyDojoBedroom_Text_0
	release
	end


friendlyBlackBeltDojoBedroom::
	lock
	faceplayer
	msgbox friendlyBlackBeltDojoBedroom_Text_0
	pokemart friendlyBlackBeltDojoBedroomShop
	msgbox friendlyBlackBeltDojoBedroom_Text_1
	release
	end


	.align 2
friendlyBlackBeltDojoBedroomShop:
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_SODA_POP
	.2byte ITEM_LEMONADE
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_NONE

tiredGirlDojo_Text_0:
	.string "AAAAAAAAAAAAAAAAAAAAAAAAAH!!!!$"

tiredGirlDojo_Text_1:
	.string "I can't take it anymore, I haven't been\n"
	.string "able to sleep even a wink for days\l"
	.string "because the person next to me\l"
	.string "constantly talks in his sleep! I want to\l"
	.string "quit!$"

tiredGirlDojo_Text_2:
	.string "...This person could benefit from a\n"
	.string "Pokémon that could help her sleep,\l"
	.string "perhaps showing her one would help?$"

tiredGirlDojo_Text_3:
	.string "So sleepy... I want to cry...$"

tiredGirlDojo_Text_4:
	.string "Huh? Do you have something to show me?$"

tiredGirlDojo_Text_5:
	.string "Your {STR_VAR_1}, it could help me\n"
	.string "fall asleep? That's amazing! I don't\l"
	.string "have to quit! I'm going to catch one\l"
	.string "right now, thank you!$"

tiredGirlDojo_Text_6:
	.string "Here, take this for helping me.$"

tiredGirlDojo_Text_7:
	.string "Thank you again! I will sleep much more\n"
	.string "easily now!$"

oldLadyDojoBedroom_Text_0:
	.string "In this dojo, we all sleep in shared\n"
	.string "spaces. It's good for the spirit of\l"
	.string "unity.$"

friendlyBlackBeltDojoBedroom_Text_0:
	.string "Hey, need some refreshments?$"

friendlyBlackBeltDojoBedroom_Text_1:
	.string "Stop by if you need more!$"
