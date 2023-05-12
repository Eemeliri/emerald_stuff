SlateportMarket_MapScripts::
	.byte 0


HyperTrainer_Lady::
	lockall
	faceplayer
	compare VAR_TEMP_2, 0
	goto_if_eq HyperTrainer_Lady_2
HyperTrainer_Lady_1:
	checkitem ITEM_BOTTLE_CAP
	compare VAR_RESULT, FALSE
	goto_if_eq HyperTrainer_Lady_5
	msgbox HyperTrainer_Lady_Text_2
	setvar VAR_0x8004, SCROLL_MULTI_HYPER_TRAINING
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, HyperTrainer_Lady_8
	case 1, HyperTrainer_Lady_9
	case 2, HyperTrainer_Lady_10
	case 3, HyperTrainer_Lady_11
	case 4, HyperTrainer_Lady_12
	case 5, HyperTrainer_Lady_13
	msgbox HyperTrainer_Lady_Text_11
	waitmessage
	releaseall
	end

HyperTrainer_Lady_2:
	msgbox HyperTrainer_Lady_Text_0
	setvar VAR_TEMP_2, 1
	goto HyperTrainer_Lady_1

HyperTrainer_Lady_5:
	msgbox HyperTrainer_Lady_Text_1
	releaseall
	end

HyperTrainer_Lady_8:
	msgbox HyperTrainer_Lady_Text_3
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxHpIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_16
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_5
	waitmessage
	releaseall
	end

HyperTrainer_Lady_9:
	msgbox HyperTrainer_Lady_Text_3
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxAttackIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_19
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_5
	waitmessage
	releaseall
	end

HyperTrainer_Lady_10:
	msgbox HyperTrainer_Lady_Text_3
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxDefenseIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_22
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_5
	waitmessage
	releaseall
	end

HyperTrainer_Lady_11:
	msgbox HyperTrainer_Lady_Text_3
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxSpAtkIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_25
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_5
	waitmessage
	releaseall
	end

HyperTrainer_Lady_12:
	msgbox HyperTrainer_Lady_Text_3
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxSpDefIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_28
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_5
	waitmessage
	releaseall
	end

HyperTrainer_Lady_13:
	msgbox HyperTrainer_Lady_Text_3
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxSpeedIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_31
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_5
	waitmessage
	releaseall
	end

HyperTrainer_Lady_16:
	msgbox HyperTrainer_Lady_Text_4
	waitmessage
	releaseall
	end

HyperTrainer_Lady_19:
	msgbox HyperTrainer_Lady_Text_6
	waitmessage
	releaseall
	end

HyperTrainer_Lady_22:
	msgbox HyperTrainer_Lady_Text_7
	waitmessage
	releaseall
	end

HyperTrainer_Lady_25:
	msgbox HyperTrainer_Lady_Text_8
	waitmessage
	releaseall
	end

HyperTrainer_Lady_28:
	msgbox HyperTrainer_Lady_Text_9
	waitmessage
	releaseall
	end

HyperTrainer_Lady_31:
	msgbox HyperTrainer_Lady_Text_10
	waitmessage
	releaseall
	end


OldMan_test::
	lock
	faceplayer
	checkitem ITEM_POTION, 1
	compare VAR_RESULT, FALSE
	goto_if_eq OldMan_test_2
	msgbox OldMan_test_Text_1
	waitmessage
	release
	end

OldMan_test_2:
	msgbox OldMan_test_Text_0
	release
	end


HyperTrainer_Lady_Text_0:
	.string "Hello there young one. Are you\n"
	.string "interested in strenghtening your\l"
	.string "Pokemon? I may not look like it, but I\l"
	.string "was quite a drill sergeant in my youth!\l"
	.string "If you find me some silvery bottle\l"
	.string "caps, I can unlock your Pokemon's true\l"
	.string "potential.$"

HyperTrainer_Lady_Text_1:
	.string "Come back when you have found some\n"
	.string "bottle caps.$"

HyperTrainer_Lady_Text_2:
	.string "Which stat would you like to train?$"

HyperTrainer_Lady_Text_3:
	.string "Alright, Please choose a Pokemon to\n"
	.string "train.$"

HyperTrainer_Lady_Text_4:
	.string "That Pokémon's HP is already at its\n"
	.string "peak!$"

HyperTrainer_Lady_Text_5:
	.string "It's done. Your Pokémon looks much\n"
	.string "stronger now.$"

HyperTrainer_Lady_Text_6:
	.string "That Pokémon's Attack is already at its\n"
	.string "peak!$"

HyperTrainer_Lady_Text_7:
	.string "That Pokémon's Defense is already at\n"
	.string "its peak!$"

HyperTrainer_Lady_Text_8:
	.string "That Pokémon's Sp. Atk is already at its\n"
	.string "peak!$"

HyperTrainer_Lady_Text_9:
	.string "That Pokémon's Sp. Def is already at its\n"
	.string "peak!$"

HyperTrainer_Lady_Text_10:
	.string "That Pokémon's Speed is already at its\n"
	.string "peak!$"

HyperTrainer_Lady_Text_11:
	.string "Changed your mind? Fine then.$"

OldMan_test_Text_0:
	.string "You don't have the item!$"

OldMan_test_Text_1:
	.string "You have a potion!$"
