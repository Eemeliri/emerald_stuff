SlateportMarket_Underwater_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportMarket_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SlateportMarket_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto_if_set FLAG_DAILY_FOSSIL, SlateportMarket_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

SlateportMarket_Underwater_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	goto hideFossil
	return


hideFossil::
	removeobject 1
	removeobject 2
	return


lootFossilLeft::
	lockall
	special RtcGetDayOfWeek
	switch VAR_RESULT
	case 0, lootFossilLeft_3
	case 1, lootFossilLeft_4
	case 2, lootFossilLeft_5
	case 3, lootFossilLeft_6
	case 4, lootFossilLeft_7
	case 5, lootFossilLeft_8
	case 6, lootFossilLeft_9
lootFossilLeft_1:
	setflag FLAG_DAILY_FOSSIL
	removeobject 1
	compare VAR_TEMP_1, 0
	goto_if_eq lootFossilLeft_11
lootFossilLeft_10:
	releaseall
	end

lootFossilLeft_3:
	giveitem ITEM_JAW_FOSSIL
	goto lootFossilLeft_1

lootFossilLeft_4:
	giveitem ITEM_CLAW_FOSSIL
	goto lootFossilLeft_1

lootFossilLeft_5:
	giveitem ITEM_DOME_FOSSIL
	goto lootFossilLeft_1

lootFossilLeft_6:
	giveitem ITEM_ROOT_FOSSIL
	goto lootFossilLeft_1

lootFossilLeft_7:
	giveitem ITEM_SAIL_FOSSIL
	goto lootFossilLeft_1

lootFossilLeft_8:
	giveitem ITEM_SKULL_FOSSIL
	goto lootFossilLeft_1

lootFossilLeft_9:
	giveitem ITEM_PLUME_FOSSIL
	goto lootFossilLeft_1

lootFossilLeft_11:
	msgbox lootFossilLeft_Text_0
	waitmessage
	setvar VAR_TEMP_1, 1
	goto lootFossilLeft_10


lootFossilRight::
	lockall
	special RtcGetDayOfWeek
	switch VAR_RESULT
	case 0, lootFossilRight_3
	case 1, lootFossilRight_4
	case 2, lootFossilRight_5
	case 3, lootFossilRight_6
	case 4, lootFossilRight_7
	case 5, lootFossilRight_8
	case 6, lootFossilRight_9
lootFossilRight_1:
	removeobject 2
	setflag FLAG_DAILY_FOSSIL
	compare VAR_TEMP_1, 0
	goto_if_eq lootFossilRight_11
lootFossilRight_10:
	releaseall
	end

lootFossilRight_3:
	giveitem ITEM_ARMOR_FOSSIL
	goto lootFossilRight_1

lootFossilRight_4:
	giveitem ITEM_COVER_FOSSIL
	goto lootFossilRight_1

lootFossilRight_5:
	giveitem ITEM_HELIX_FOSSIL
	goto lootFossilRight_1

lootFossilRight_6:
	giveitem ITEM_JAW_FOSSIL
	goto lootFossilRight_1

lootFossilRight_7:
	giveitem ITEM_CLAW_FOSSIL
	goto lootFossilRight_1

lootFossilRight_8:
	giveitem ITEM_DOME_FOSSIL
	goto lootFossilRight_1

lootFossilRight_9:
	giveitem ITEM_ROOT_FOSSIL
	goto lootFossilRight_1

lootFossilRight_11:
	msgbox lootFossilLeft_Text_0
	waitmessage
	setvar VAR_TEMP_1, 1
	goto lootFossilRight_10


lootFossilLeft_Text_0:
	.string "The seafloor sand seems to shift\n"
	.string "rapidly, perhaps another day there will\l"
	.string "be more fossils to collect?$"
