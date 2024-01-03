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
	msgbox HyperTrainer_Lady_Text_12
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
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq HyperTrainer_Lady_16
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxHpIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_34
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_6
	waitmessage
	releaseall
	end

HyperTrainer_Lady_9:
	msgbox HyperTrainer_Lady_Text_3
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq HyperTrainer_Lady_19
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxAttackIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_37
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_6
	waitmessage
	releaseall
	end

HyperTrainer_Lady_10:
	msgbox HyperTrainer_Lady_Text_3
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq HyperTrainer_Lady_22
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxDefenseIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_40
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_6
	waitmessage
	releaseall
	end

HyperTrainer_Lady_11:
	msgbox HyperTrainer_Lady_Text_3
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq HyperTrainer_Lady_25
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxSpAtkIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_43
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_6
	waitmessage
	releaseall
	end

HyperTrainer_Lady_12:
	msgbox HyperTrainer_Lady_Text_3
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq HyperTrainer_Lady_28
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxSpDefIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_46
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_6
	waitmessage
	releaseall
	end

HyperTrainer_Lady_13:
	msgbox HyperTrainer_Lady_Text_3
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq HyperTrainer_Lady_31
	copyvar VAR_RESULT, VAR_0x8004
	specialvar VAR_0x8008, trymaxSpeedIV
	compare VAR_0x8008, FALSE
	goto_if_eq HyperTrainer_Lady_49
	special recalculateStats
	playfanfare MUS_LEVEL_UP
	waitfanfare
	removeitem ITEM_BOTTLE_CAP, 1
	msgbox HyperTrainer_Lady_Text_6
	waitmessage
	releaseall
	end

HyperTrainer_Lady_16:
	msgbox HyperTrainer_Lady_Text_4
	waitmessage
	releaseall
	end

HyperTrainer_Lady_19:
	msgbox HyperTrainer_Lady_Text_4
	waitmessage
	releaseall
	end

HyperTrainer_Lady_22:
	msgbox HyperTrainer_Lady_Text_4
	waitmessage
	releaseall
	end

HyperTrainer_Lady_25:
	msgbox HyperTrainer_Lady_Text_4
	waitmessage
	releaseall
	end

HyperTrainer_Lady_28:
	msgbox HyperTrainer_Lady_Text_4
	waitmessage
	releaseall
	end

HyperTrainer_Lady_31:
	msgbox HyperTrainer_Lady_Text_4
	waitmessage
	releaseall
	end

HyperTrainer_Lady_34:
	msgbox HyperTrainer_Lady_Text_5
	waitmessage
	releaseall
	end

HyperTrainer_Lady_37:
	msgbox HyperTrainer_Lady_Text_7
	waitmessage
	releaseall
	end

HyperTrainer_Lady_40:
	msgbox HyperTrainer_Lady_Text_8
	waitmessage
	releaseall
	end

HyperTrainer_Lady_43:
	msgbox HyperTrainer_Lady_Text_9
	waitmessage
	releaseall
	end

HyperTrainer_Lady_46:
	msgbox HyperTrainer_Lady_Text_10
	waitmessage
	releaseall
	end

HyperTrainer_Lady_49:
	msgbox HyperTrainer_Lady_Text_11
	waitmessage
	releaseall
	end


ShouldWarpToVerityCave::
	lockall
	goto_if_eq VAR_VERITY_CAVERN_STATE, 3, warpToCave2
	warp MAP_VERITY_CAVERN, 21, 37
	releaseall
	return


warpToCave2::
	warp MAP_VERITY_CAVERN2, 18, 32
	releaseall
	return


Oldman_Mint_Mart::
	lock
	faceplayer
	msgbox Oldman_Mint_Mart_Text_0
	msgbox Oldman_Mint_Mart_Text_1
	special RtcGetDayOfWeek
	switch VAR_RESULT
	case 0, Oldman_Mint_Mart_3
	case 1, Oldman_Mint_Mart_4
	case 2, Oldman_Mint_Mart_5
	case 3, Oldman_Mint_Mart_6
	case 4, Oldman_Mint_Mart_7
	case 5, Oldman_Mint_Mart_8
	case 6, Oldman_Mint_Mart_9
	msgbox Oldman_Mint_Mart_Text_2
	pokemart MintShopSunday
Oldman_Mint_Mart_1:
	msgbox Oldman_Mint_Mart_Text_3
	waitmessage
	release
	end

Oldman_Mint_Mart_3:
	pokemart MintShopSunday
	goto Oldman_Mint_Mart_1

Oldman_Mint_Mart_4:
	pokemart MintShopMonday
	goto Oldman_Mint_Mart_1

Oldman_Mint_Mart_5:
	pokemart MintShopTuesday
	goto Oldman_Mint_Mart_1

Oldman_Mint_Mart_6:
	pokemart MintShopWednesday
	goto Oldman_Mint_Mart_1

Oldman_Mint_Mart_7:
	pokemart MintShopThursday
	goto Oldman_Mint_Mart_1

Oldman_Mint_Mart_8:
	pokemart MintShopFriday
	goto Oldman_Mint_Mart_1

Oldman_Mint_Mart_9:
	pokemart MintShopSaturday
	goto Oldman_Mint_Mart_1


miscItemMartNPC::
	lock
	faceplayer
	msgbox miscItemMartNPC_Text_0
	pokemart miscItemMart
	msgbox miscItemMartNPC_Text_1
	waitmessage
	release
	end


berryMartNPC::
	lock
	faceplayer
	msgbox berryMartNPC_Text_0
	pokemart miscBerryMart
	msgbox berryMartNPC_Text_1
	waitmessage
	release
	end


stressedConsumerNPC::
	lock
	faceplayer
	msgbox stressedConsumerNPC_Text_0
	waitmessage
	release
	end


sailorShopperNPC::
	lock
	faceplayer
	msgbox sailorShopperNPC_Text_0
	waitmessage
	release
	end


sailorWatcherNPC::
	lock
	faceplayer
	msgbox sailorWatcherNPC_Text_0
	waitmessage
	release
	end


watcherOldMan::
	lock
	msgbox watcherOldMan_Text_0
	waitmessage
	release
	end


azumarillPartner::
	lock
	faceplayer
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	waitmoncry
	release
	end


hyperTrainingSign::
	msgbox hyperTrainingSign_Text_0, MSGBOX_SIGN
	end


miscItemMartSign::
	msgbox miscItemMartSign_Text_0, MSGBOX_SIGN
	end


miscBerryMartSign::
	msgbox miscBerryMartSign_Text_0, MSGBOX_SIGN
	end


mysticTrader::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_ALAKAZITE, mysticTrader_5
mysticTrader_4:
	goto_if_set FLAG_ITEM_ALAKAZITE, mysticTrader_3
	msgbox mysticTrader_Text_2
	checkitem ITEM_PSYCHIC_GEM
	compare VAR_RESULT, FALSE
	goto_if_eq mysticTrader_9
	msgbox mysticTrader_Text_3
	giveitem ITEM_ALAKAZITE
	removeitem ITEM_PSYCHIC_GEM, 1
	setflag FLAG_ITEM_ALAKAZITE
	waitmessage
	releaseall
	end

mysticTrader_2:
	msgbox mysticTrader_Text_0
	release
	end

mysticTrader_3:
	msgbox mysticTrader_Text_1
	release
	end

mysticTrader_5:
	goto_if_set FLAG_IS_CHAMPION, mysticTrader_2
	goto mysticTrader_4

mysticTrader_9:
	releaseall
	end


mysticSign::
	lock
	msgbox mysticSign_Text_0
	waitmessage
	release
	end


	.align 2
miscBerryMart:
	.2byte ITEM_LIECHI_BERRY
	.2byte ITEM_GANLON_BERRY
	.2byte ITEM_SALAC_BERRY
	.2byte ITEM_PETAYA_BERRY
	.2byte ITEM_APICOT_BERRY
	.2byte ITEM_LANSAT_BERRY
	.2byte ITEM_STARF_BERRY
	.2byte ITEM_JABOCA_BERRY
	.2byte ITEM_ROWAP_BERRY
	.2byte ITEM_NONE

	.align 2
miscItemMart:
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_ABSORB_BULB
	.2byte ITEM_DESTINY_KNOT
	.2byte ITEM_COVERT_CLOAK
	.2byte ITEM_NONE

	.align 2
MintShopSunday:
	.2byte ITEM_ADAMANT_MINT
	.2byte ITEM_BOLD_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_NONE

	.align 2
MintShopMonday:
	.2byte ITEM_BRAVE_MINT
	.2byte ITEM_CALM_MINT
	.2byte ITEM_CAREFUL_MINT
	.2byte ITEM_NONE

	.align 2
MintShopTuesday:
	.2byte ITEM_GENTLE_MINT
	.2byte ITEM_HASTY_MINT
	.2byte ITEM_IMPISH_MINT
	.2byte ITEM_NONE

	.align 2
MintShopWednesday:
	.2byte ITEM_JOLLY_MINT
	.2byte ITEM_LAX_MINT
	.2byte ITEM_LONELY_MINT
	.2byte ITEM_NONE

	.align 2
MintShopThursday:
	.2byte ITEM_MILD_MINT
	.2byte ITEM_MODEST_MINT
	.2byte ITEM_NAIVE_MINT
	.2byte ITEM_NONE

	.align 2
MintShopFriday:
	.2byte ITEM_NAUGHTY_MINT
	.2byte ITEM_QUIET_MINT
	.2byte ITEM_RASH_MINT
	.2byte ITEM_NONE

	.align 2
MintShopSaturday:
	.2byte ITEM_RELAXED_MINT
	.2byte ITEM_SASSY_MINT
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_TIMID_MINT
	.2byte ITEM_NONE

HyperTrainer_Lady_Text_0:
	.string "Hello there young one. Are you\n"
	.string "interested in strenghtening your\l"
	.string "Pokemon? I may not look like it, but I\l"
	.string "was quite a drill sergeant in my youth!\l"
	.string "If you find me some silvery bottle caps,\l"
	.string "I can unlock your Pokemon's true\l"
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
	.string "Having trouble deciding? Take your\n"
	.string "time.$"

HyperTrainer_Lady_Text_5:
	.string "That Pokémon's HP is already at its\n"
	.string "peak!$"

HyperTrainer_Lady_Text_6:
	.string "It's done. Your Pokémon looks much\n"
	.string "stronger now.$"

HyperTrainer_Lady_Text_7:
	.string "That Pokémon's Attack is already at its\n"
	.string "peak!$"

HyperTrainer_Lady_Text_8:
	.string "That Pokémon's Defense is already at\n"
	.string "its peak!$"

HyperTrainer_Lady_Text_9:
	.string "That Pokémon's Sp. Atk is already at its\n"
	.string "peak!$"

HyperTrainer_Lady_Text_10:
	.string "That Pokémon's Sp. Def is already at its\n"
	.string "peak!$"

HyperTrainer_Lady_Text_11:
	.string "That Pokémon's Speed is already at its\n"
	.string "peak!$"

HyperTrainer_Lady_Text_12:
	.string "Changed your mind? Fine then.$"

Oldman_Mint_Mart_Text_0:
	.string "Hello! Are you interested in fresh mints\n"
	.string "I've harvested today?$"

Oldman_Mint_Mart_Text_1:
	.string "This is what I have gathered for today.$"

Oldman_Mint_Mart_Text_2:
	.string "It seems you are lost in time. I think I\n"
	.string "have something for you regardless.$"

Oldman_Mint_Mart_Text_3:
	.string "Come again soon.$"

miscItemMartNPC_Text_0:
	.string "Hey you! Take a loot at my wares!$"

miscItemMartNPC_Text_1:
	.string "Come back to buy more soon!$"

berryMartNPC_Text_0:
	.string "Greetings. May I interest you with\n"
	.string "these rare berries?$"

berryMartNPC_Text_1:
	.string "I hope to see you again!$"

stressedConsumerNPC_Text_0:
	.string "Ever since this harbor market was built,\n"
	.string "many strong trainers have started\l"
	.string "visiting the city.$"

sailorShopperNPC_Text_0:
	.string "Stocking up supplies for long trips is a\n"
	.string "must for a sailor. Good thing Slateport\l"
	.string "offers it all!$"

sailorWatcherNPC_Text_0:
	.string "Ever seen a Gyarados leap over the bow\n"
	.string "at sunrise? There's no sight more\l"
	.string "majestic... or terrifying, if you're not\l"
	.string "prepared!$"

watcherOldMan_Text_0:
	.string "This place used to be nothing more than\n"
	.string "a few houses in my youth. Time truly\l"
	.string "travels fast when you're with Pokémon.\l"
	.string "I only wish I had explored the world\l"
	.string "more.$"

hyperTrainingSign_Text_0:
	.string "Former drill sergeant offering hyper\n"
	.string "training services.$"

miscItemMartSign_Text_0:
	.string "Market goods for affordable prices!\n"
	.string "Buy!!$"

miscBerryMartSign_Text_0:
	.string "Rare berries from distant lands.$"

mysticTrader_Text_0:
	.string "I knew you were destined for greatness,\n"
	.string "champion of Hoenn.$"

mysticTrader_Text_1:
	.string "I look forward to seeing your progress.$"

mysticTrader_Text_2:
	.string "You! Yes you, I sense great potential\n"
	.string "within you. I can aid your growth\l"
	.string "towards greatness if you bring me a\l"
	.string "Psychic Gem.$"

mysticTrader_Text_3:
	.string "Yes! That is truly a beatiful specimen\n"
	.string "of a Psychic Gem! As promised I will\l"
	.string "grant you this stone to foster your\l"
	.string "growth towards greatness.$"

mysticSign_Text_0:
	.string "Mystic Maya sees all.$"
