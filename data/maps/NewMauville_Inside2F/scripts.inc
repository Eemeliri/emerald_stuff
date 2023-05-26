NewMauville_Inside2F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside2F_MapScripts_MAP_SCRIPT_ON_RESUME
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

NewMauville_Inside2F_MapScripts_MAP_SCRIPT_ON_RESUME:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, TryRemoveElectrode
	return

NewMauville_Inside2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_unset FLAG_HIDE_ELECTRODE1, ShowElectrode1
	call_if_unset FLAG_HIDE_ELECTRODE2, ShowElectrode2
	return


ShowElectrode1::
	clearflag FLAG_HIDE_ELECTRODE1
	return


ShowElectrode2::
	clearflag FLAG_HIDE_ELECTRODE2
	return


TryRemoveElectrode::
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne TryRemoveElectrode_2
TryRemoveElectrode_1:
	removeobject VAR_LAST_TALKED
	return

TryRemoveElectrode_2:
	goto Common_EventScript_NopReturn
	goto TryRemoveElectrode_1


Electrode1::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 35
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, defeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, defeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, defeatedElectrode1
	setflag FLAG_HIDE_ELECTRODE1
	release
	end


Electrode2::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 35
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, defeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, defeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, defeatedElectrode2
	setflag FLAG_HIDE_ELECTRODE2
	release
	end


defeatedElectrode1::
	setflag FLAG_HIDE_ELECTRODE1
	goto Common_EventScript_RemoveStaticPokemon
	end


defeatedElectrode2::
	setflag FLAG_HIDE_ELECTRODE2
	goto Common_EventScript_RemoveStaticPokemon
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
	warp MAP_STARK_MOUNTAIN2, 42, 75
tempDistortion_1:
	release
	end

tempDistortion_2:
	warp MAP_DISTORTION_WORLD, 18, 32
	goto tempDistortion_1


tempDistortion_Text_0:
	.string "Go to distortion world?$"
