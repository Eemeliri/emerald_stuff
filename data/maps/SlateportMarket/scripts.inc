SlateportMarket_MapScripts::
	.byte 0


HyperTrainer_Lady::
	lockall
	faceplayer
	compare VAR_TEMP_2, 0
	goto_if_eq HyperTrainer_Lady_2
HyperTrainer_Lady_1:
	msgbox HyperTrainer_Lady_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_ne HyperTrainer_Lady_5
HyperTrainer_Lady_4:
	waitmessage
	releaseall
	end

HyperTrainer_Lady_2:
	msgbox HyperTrainer_Lady_Text_0
	setvar VAR_TEMP_2, 1
	goto HyperTrainer_Lady_1

HyperTrainer_Lady_5:
	msgbox HyperTrainer_Lady_Text_2
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	special maxAttackIV
	msgbox HyperTrainer_Lady_Text_3
	goto HyperTrainer_Lady_4


HyperTrainer_Lady_Text_0:
	.string "Hello there young one. Are you\n"
	.string "interested in strenghtening your\l"
	.string "Pokemon? I may not look like it, but I\l"
	.string "was quite a drill sergeant in my youth!\l"
	.string "If you find me some silvery bottle\l"
	.string "caps, I can unlock your Pokemon's true\l"
	.string "potential.$"

HyperTrainer_Lady_Text_1:
	.string "Are you interested in my Hyper Training\n"
	.string "services?$"

HyperTrainer_Lady_Text_2:
	.string "Alright, Please choose a Pokemon to\n"
	.string "train.$"

HyperTrainer_Lady_Text_3:
	.string "It's done. Your Pokémon looks much\n"
	.string "stronger now.$"
