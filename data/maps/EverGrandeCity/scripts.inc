EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "Entering Victory Road$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "Entering Pokémon League\n"
	.string "Center Gate$"

EverGrandeCity_Text_CitySign:
	.string "Ever Grande City\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and Pokémon.”$"

birchPostgameEverGrande::
	lock
	faceplayer
	compare VAR_SHAYMIN_QUEST_STATE, 0
	goto_if_eq birchPostgameEverGrande_2
	compare VAR_SHAYMIN_QUEST_STATE, 3
	goto_if_eq birchPostgameEverGrande_3
	compare VAR_SHAYMIN_QUEST_STATE, 4
	goto_if_eq birchPostgameEverGrande_4
	msgbox birchPostgameEverGrande_Text_8
	checkitem ITEM_GRACIDEA
	compare VAR_RESULT, FALSE
	goto_if_eq birchPostgameEverGrande_9
	msgbox birchPostgameEverGrande_Text_10
	setvar VAR_SHAYMIN_QUEST_STATE, 3
	release
	end

birchPostgameEverGrande_2:
	msgbox birchPostgameEverGrande_Text_0
	msgbox birchPostgameEverGrande_Text_1
	applymovement 2, birchFaceUpEverGrande
	msgbox birchPostgameEverGrande_Text_2
	msgbox birchPostgameEverGrande_Text_3
	msgbox birchPostgameEverGrande_Text_4
	setvar VAR_SHAYMIN_QUEST_STATE, 1
	release
	end

birchPostgameEverGrande_3:
	msgbox birchPostgameEverGrande_Text_5
	release
	end

birchPostgameEverGrande_4:
	msgbox birchPostgameEverGrande_Text_6
	waitmessage
	msgbox birchPostgameEverGrande_Text_7
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 2
	waitfieldeffect FLDEFF_NPCFLY_OUT
	setflag FLAG_HIDE_POSTGAME_EVERGRANDE_BIRCH
	setvar VAR_SHAYMIN_QUEST_STATE, 5
	release
	end

birchPostgameEverGrande_9:
	msgbox birchPostgameEverGrande_Text_9
	release
	end


birchFaceUpEverGrande:
	walk_in_place_up
	step_end

stoneTabletEverGrande::
	lock
	compare VAR_SHAYMIN_QUEST_STATE, 3
	goto_if_lt stoneTabletEverGrande_2
	msgbox stoneTabletEverGrande_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq stoneTabletEverGrande_5
stoneTabletEverGrande_4:
	release
	end

stoneTabletEverGrande_2:
	msgbox stoneTabletEverGrande_Text_0
	release
	end

stoneTabletEverGrande_5:
	warpteleport MAP_FLOWER_PARADISE, 5, 146
	goto stoneTabletEverGrande_4


birchPostgameEverGrande_Text_0:
	.string "Hello {PLAYER}, how are you doing? Me?\n"
	.string "I'm investigating this stone tablet. I\l"
	.string "got a message from my colleague Prof.\l"
	.string "Rowan in Sinnoh region. He mentioned\l"
	.string "that he found a similar stone tablet\l"
	.string "over there and wanted me to\l"
	.string "investigate the similarities.$"

birchPostgameEverGrande_Text_1:
	.string "Perhaps you could join me? It might\n"
	.string "prove insightful!$"

birchPostgameEverGrande_Text_2:
	.string "I've almost finished transcribing the\n"
	.string "text writen here, it has worn off over\l"
	.string "the years, but I think I've got the gist\l"
	.string "of the contents.$"

birchPostgameEverGrande_Text_3:
	.string "The stone mentions a specific type of\n"
	.string "flower that resonates with a certain\l"
	.string "Pokémon.$"

birchPostgameEverGrande_Text_4:
	.string "I wonder where we could find that\n"
	.string "specific flower though...$"

birchPostgameEverGrande_Text_5:
	.string "Come on now, try touching the statue\n"
	.string "with the Gracidea flower, {PLAYER}!$"

birchPostgameEverGrande_Text_6:
	.string "What did you find on the other side,\n"
	.string "{PLAYER}?$"

birchPostgameEverGrande_Text_7:
	.string "You caught a Shaymin? That's amazing!\n"
	.string "That is an extremely rare Pokémon, that\l"
	.string "can purify pollution. I can't wait to\l"
	.string "tell Prof. Rowan about this! You keep up\l"
	.string "the good work, I'll head back to\l"
	.string "Littleroot now. Take care!$"

birchPostgameEverGrande_Text_8:
	.string "I wonder where we could find someone\n"
	.string "specialized in flowers...$"

birchPostgameEverGrande_Text_9:
	.string "Not yet? I see. Perhaps we should\n"
	.string "investigate places specialized in\l"
	.string "flowers or berries of Hoenn region.$"

birchPostgameEverGrande_Text_10:
	.string "That flower, it seems to be reacting to\n"
	.string "the stone tablet somehow! Try bringing\l"
	.string "it closer to it!$"

stoneTabletEverGrande_Text_0:
	.string "The stone tablet seems to contain\n"
	.string "ancient text, but it has worn off over\l"
	.string "the years of being exposed to the\l"
	.string "elements.$"

stoneTabletEverGrande_Text_1:
	.string "The stone tablet emites a faint hum in\n"
	.string "resonance with the Gracidea Flower.\l"
	.string "Touch the stone?$"
