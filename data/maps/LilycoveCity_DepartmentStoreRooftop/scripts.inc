LilycoveCity_DepartmentStoreRooftop_MapScripts::
	.byte 0

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	special RtcGetDayOfWeek
	switch VAR_RESULT
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Saturday
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Sunday
	case 2, LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Monday
	case 3, LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Tuesday
	case 4, LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Wednesday
	case 5, LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Thurday
	pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Saturday::
    pokemart LilycoveCity_DepartmentStoreRooftop_PokemartStones_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Sunday::
    pokemart LilycoveCity_DepartmentStoreRooftop_PokemartHoldEvo_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Monday::
    pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartBigDecor_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Tuesday::
    pokemart LilycoveCity_DepartmentStoreRooftop_PokemartEvo_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Wednesday::
    pokemartdecoration LilycoveCity_DepartmentStoreRooftop_PokemartMiscDecor_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SaleWoman_Thurday::
    pokemart LilycoveCity_DepartmentStoreRooftop_PokemartMisc_ClearOutSale
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartStones_ClearOutSale:
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_ICE_STONE
	.2byte 0
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartHoldEvo_ClearOutSale:
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_METAL_COAT
	.2byte ITEM_UPGRADE
	.2byte ITEM_DEEP_SEA_SCALE
	.2byte ITEM_DEEP_SEA_TOOTH
	.2byte ITEM_DUBIOUS_DISC
	.2byte ITEM_ELECTIRIZER
	.2byte ITEM_MAGMARIZER
	.2byte ITEM_OVAL_STONE
	.2byte ITEM_PROTECTOR
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_RAZOR_FANG
	.2byte ITEM_REAPER_CLOTH
	.2byte ITEM_PRISM_SCALE
	.2byte ITEM_SACHET
	.2byte ITEM_WHIPPED_DREAM
	.2byte 0
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartBigDecor_ClearOutSale:
	.2byte DECOR_LAPRAS_DOLL
	.2byte DECOR_SNORLAX_DOLL
	.2byte DECOR_VENUSAUR_DOLL
	.2byte DECOR_CHARIZARD_DOLL
	.2byte DECOR_BLASTOISE_DOLL
	.2byte 0
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartEvo_ClearOutSale:
	.2byte ITEM_GALARICA_CUFF
	.2byte ITEM_GALARICA_WREATH
	.2byte ITEM_BLACK_AUGURITE
	.2byte ITEM_PEAT_BLOCK
	.2byte ITEM_LINKING_CORD
	.2byte 0
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartMiscDecor_ClearOutSale:
	.2byte DECOR_KISS_POSTER
	.2byte DECOR_KISS_CUSHION
	.2byte DECOR_SMOOCHUM_DOLL
	.2byte DECOR_TOGEPI_DOLL
	.2byte DECOR_MEOWTH_DOLL
	.2byte DECOR_CLEFAIRY_DOLL
	.2byte DECOR_DITTO_DOLL
	.2byte DECOR_CYNDAQUIL_DOLL
	.2byte DECOR_CHIKORITA_DOLL
	.2byte DECOR_TOTODILE_DOLL
	.2byte 0
	release
	end


	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartMisc_ClearOutSale:
	.2byte ITEM_EVERSTONE
	.2byte ITEM_RED_SCARF
	.2byte ITEM_BLUE_SCARF
	.2byte ITEM_PINK_SCARF
	.2byte ITEM_GREEN_SCARF
	.2byte ITEM_YELLOW_SCARF
	.2byte ITEM_DAMP_ROCK
	.2byte ITEM_HEAT_ROCK
	.2byte ITEM_SMOOTH_ROCK
	.2byte ITEM_ICY_ROCK
	.2byte 0
	release
	end

	.align 2
LilycoveCity_DepartmentStoreRooftop_PokemartDecor_ClearOutSale:
	.2byte DECOR_MUD_BALL
	.2byte DECOR_FENCE_LENGTH
	.2byte DECOR_FENCE_WIDTH
	.2byte DECOR_TIRE
	.2byte DECOR_BREAKABLE_DOOR
	.2byte DECOR_SOLID_BOARD
	.2byte DECOR_SAND_ORNAMENT
	.2byte DECOR_STAND
	.2byte DECOR_SLIDE
	.2byte DECOR_TV
	.2byte DECOR_ROUND_TV
	.2byte DECOR_CUTE_TV
	.2byte DECOR_WAILMER_DOLL
	.2byte DECOR_RHYDON_DOLL
	.2byte 0
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ThirstyMan::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty, MSGBOX_NPC
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_VendingMachine::
	lockall
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	showmoneybox 0, 0
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink::
	multichoice 16, 0, MULTI_VENDING_MACHINE, FALSE
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater
	case 1, LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop
	case 2, LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_FreshWater::
	setvar VAR_TEMP_0, ITEM_FRESH_WATER
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_SodaPop::
	setvar VAR_TEMP_0, ITEM_SODA_POP
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_Lemonade::
	setvar VAR_TEMP_0, ITEM_LEMONADE
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater::
	checkmoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop::
	checkmoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade::
	checkmoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater::
	removemoney 200
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop::
	removemoney 300
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade::
	removemoney 350
	return

LilycoveCity_DepartmentStoreRooftop_EventScript_TryBuyDrink::
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_CheckMoneyLemonade
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	call_if_eq VAR_TEMP_1, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyFreshWater
	call_if_eq VAR_TEMP_1, 1, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneySodaPop
	call_if_eq VAR_TEMP_1, 2, LilycoveCity_DepartmentStoreRooftop_EventScript_RemoveMoneyLemonade
	updatemoneybox
	bufferitemname STR_VAR_1, VAR_TEMP_0
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 chance of an additional drink dropping
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	random 64  @ 1/64 * the prev 1/64 chance of a third additional drink dropping, ~ 0.02% chance
	goto_if_ne VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	checkitemspace VAR_TEMP_0
	goto_if_eq VAR_RESULT, 0, LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink
	playse SE_VEND
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown, MSGBOX_DEFAULT
	additem VAR_TEMP_0
	bufferitemname STR_VAR_2, VAR_TEMP_0
	bufferstdstring STR_VAR_3, STDSTRING_ITEMS
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseNewDrink::
	message LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike
	waitmessage
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ChooseDrink
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NotEnoughMoneyForDrink::
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_NoRoomForDrink::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_ExitVendingMachine::
	hidemoneybox
	releaseall
	end

LilycoveCity_DepartmentStoreRooftop_Text_SetDatesForClearOutSales:
	.string "They have items that you can only get\n"
	.string "here.\p"
	.string "But the items they sell changes every\n"
	.string "day!$"

LilycoveCity_DepartmentStoreRooftop_Text_BoneDryThirsty:
	.string "Ohh… I'm bone-dry thirsty!$"

LilycoveCity_DepartmentStoreRooftop_Text_WhichDrinkWouldYouLike:
	.string "It's a Vending Machine.\n"
	.string "Which drink would you like?$"

LilycoveCity_DepartmentStoreRooftop_Text_CanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "A can of {STR_VAR_1} dropped down.$"

LilycoveCity_DepartmentStoreRooftop_Text_ExtraCanOfDrinkDroppedDown:
	.string "Clang!\p"
	.string "Score! An extra can of {STR_VAR_1}\n"
	.string "dropped down!$"

LilycoveCity_DepartmentStoreRooftop_Text_NotEnoughMoney:
	.string "Not enough money…$"

LilycoveCity_DepartmentStoreRooftop_Text_DecidedAgainstBuyingDrink:
	.string "Decided against buying a drink.$"
