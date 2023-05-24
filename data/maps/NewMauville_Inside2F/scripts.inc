NewMauville_Inside2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside2F_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

NewMauville_Inside2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_set FLAG_CAUGHT_ZAPDOS, tryHideZapdos
	call_if_unset FLAG_CAUGHT_ZAPDOS, tryShowZapdos
	return

NewMauville_Inside2F_MapScripts_MAP_SCRIPT_ON_RESUME:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside2F_OnResume
	return


tryHideZapdos::
	setflag FLAG_HIDE_ZAPDOS
	return


tryShowZapdos::
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_ZAPDOS
	return


NewMauville_Inside2F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, tryRemoveZapdos
	return


tryRemoveZapdos::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne tryRemoveZapdos_2
tryRemoveZapdos_1:
	removeobject 1
	return

tryRemoveZapdos_2:
	goto Common_EventScript_NopReturn
	goto tryRemoveZapdos_1


EventScript_Zapdos::
	lock
	faceplayer
	waitse
	delay 20
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 20
	seteventmon SPECIES_ZAPDOS, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq EventScript_Zapdos_2
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq EventScript_Zapdos_3
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq EventScript_Zapdos_4
EventScript_Zapdos_1:
	setflag FLAG_CAUGHT_ZAPDOS
	release
	end

EventScript_Zapdos_2:
	goto defeatedZapdos
	goto EventScript_Zapdos_1

EventScript_Zapdos_3:
	goto ranZapdos
	goto EventScript_Zapdos_1

EventScript_Zapdos_4:
	goto ranZapdos
	goto EventScript_Zapdos_1


ranZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end


defeatedZapdos::
	setvar VAR_0x8004, SPECIES_ZAPDOS
	goto Common_EventScript_LegendaryFlewAway
	end


stepOnButton1::
	lockall
	playse SE_PIN
	addvar VAR_TEMP_5, 1
	setmetatile 11, 16, METATILE_BikeShop_Button_Pressed, FALSE
	setvar VAR_TEMP_1, 1
	special DrawWholeMapView
	call checkButtonCount
	releaseall
	end


stepOnButton2::
	lockall
	playse SE_PIN
	addvar VAR_TEMP_5, 1
	setmetatile 11, 11, METATILE_BikeShop_Button_Pressed, FALSE
	setvar VAR_TEMP_2, 1
	special DrawWholeMapView
	call checkButtonCount
	releaseall
	end


stepOnButton3::
	lockall
	playse SE_PIN
	addvar VAR_TEMP_5, 1
	setmetatile 28, 16, METATILE_BikeShop_Button_Pressed, FALSE
	setvar VAR_TEMP_3, 1
	special DrawWholeMapView
	call checkButtonCount
	releaseall
	end


stepOnButton4::
	lockall
	playse SE_PIN
	addvar VAR_TEMP_5, 1
	setmetatile 28, 11, METATILE_BikeShop_Button_Pressed, FALSE
	setvar VAR_TEMP_4, 1
	special DrawWholeMapView
	call checkButtonCount
	releaseall
	end


checkButtonCount::
	compare VAR_TEMP_5, 4
	goto_if_eq checkButtonCount_1
	return

checkButtonCount_1:
	call TurnOffZapdosGenerator
	call bringDownTheDoor
	special DrawWholeMapView
	return


bringDownTheDoor::
	setmetatile 17, 4, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 17, 5, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 17, 6, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 17, 7, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 17, 8, METATILE_BikeShop_Wall_Edge_Top, FALSE
	return


TurnOffZapdosGenerator::
	setmetatile 18, 10, METATILE_BikeShop_Generator_Off_Tile0, TRUE
	setmetatile 19, 10, METATILE_BikeShop_Generator_Off_Tile1, TRUE
	setmetatile 20, 10, METATILE_BikeShop_Generator_Off_Tile2, TRUE
	setmetatile 21, 10, METATILE_BikeShop_Generator_Off_Tile3, TRUE
	setmetatile 18, 11, METATILE_BikeShop_Generator_Off_Tile4, TRUE
	setmetatile 19, 11, METATILE_BikeShop_Generator_Off_Tile5, TRUE
	setmetatile 20, 11, METATILE_BikeShop_Generator_Off_Tile6, TRUE
	setmetatile 21, 11, METATILE_BikeShop_Generator_Off_Tile7, TRUE
	playse SE_DOOR
	return


tempDistortion::
	lock
	faceplayer
	msgbox tempDistortion_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq tempDistortion_2
tempDistortion_1:
	release
	end

tempDistortion_2:
	warp MAP_DISTORTION_WORLD, 18, 32
	goto tempDistortion_1


tempDistortion_Text_0:
	.string "Go to distortion world?$"
