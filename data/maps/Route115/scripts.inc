
Route115_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	.byte 0

Route115_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_EventScript_PlaceTilesRoute115West
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_EventScript_PlaceTilesRoute115East
	end

Route115_OnTransition:
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST, AbnormalWeather_StartGroudonWeather
	end

Route115_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route115_EventScript_Woman::
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end

Route115_EventScript_RouteSignRustboro::
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route115_EventScript_MeteorFallsSign::
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route115_EventScript_Timothy::
	trainerbattle_single TRAINER_TIMOTHY_1, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat, Route115_EventScript_RegisterTimothy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchTimothy
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterTimothy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_TimothyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TIMOTHY_1
	release
	end

Route115_EventScript_RematchTimothy::
	trainerbattle_rematch TRAINER_TIMOTHY_1, Route115_Text_TimothyRematchIntro, Route115_Text_TimothyRematchDefeat
	msgbox Route115_Text_TimothyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Koichi::
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_1, Route115_Text_NobIntro, Route115_Text_NobDefeat, Route115_EventScript_RegisterNob
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchNob
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterNob::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_NobRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_NOB_1
	release
	end

Route115_EventScript_RematchNob::
	trainerbattle_rematch TRAINER_NOB_1, Route115_Text_NobRematchIntro, Route115_Text_NobRematchDefeat
	msgbox Route115_Text_NobPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Cyndy::
	trainerbattle_single TRAINER_CYNDY_1, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat, Route115_EventScript_RegisterCyndy
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route115_EventScript_RematchCyndy
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_RegisterCyndy::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route115_Text_CyndyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CYNDY_1
	release
	end

Route115_EventScript_RematchCyndy::
	trainerbattle_rematch TRAINER_CYNDY_1, Route115_Text_CyndyRematchIntro, Route115_Text_CyndyRematchDefeat
	msgbox Route115_Text_CyndyPostRematch, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Hector::
	trainerbattle_single TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Kyra::
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Jaiden::
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Alix::
	trainerbattle_single TRAINER_ALIX, Route115_Text_AlixIntro, Route115_Text_AlixDefeat
	msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Helene::
	trainerbattle_single TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat
	msgbox Route115_Text_HelenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Marlene::
	trainerbattle_single TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_Text_NeverKnowWhenCavePokemonWillAppear:
	.string "Exploring a cave isn't like walking\n"
	.string "on a road.\p"
	.string "You never know when wild Pokémon will\n"
	.string "appear. It's full of suspense.$"

Route115_Text_RouteSignRustboro:
	.string "Route 115\n"
	.string "{DOWN_ARROW} Rustboro City$"

Route115_Text_MeteorFallsSign:
	.string "Meteor Falls\n"
	.string "Fallarbor Town through here$"

Route115_Falkner::
	lock
	msgbox Route115_Falkner_Text_0
	faceplayer
	applymovement 25, route115falknerPidgeotto
	msgbox Route115_Falkner_Text_1
	msgbox Route115_Falkner_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Route115_Falkner_2
	msgbox Route115_Falkner_Text_4
	trainerbattle_no_intro TRAINER_ROUTE115_FALKNER, Route115_Falkner_Text_5
	msgbox Route115_Falkner_Text_6
	msgbox Route115_Falkner_Text_7
	msgbox Route115_Falkner_Text_8
	giveitem ITEM_TM19, 1
	waitmessage
	msgbox Route115_Falkner_Text_9
	fadescreen FADE_TO_BLACK
	delay 30
	closemessage
	removeobject 24
	removeobject 25
	delay 30
	fadescreen FADE_FROM_BLACK
	setflag FLAG_HIDE_ROUTE115_FALKNER
	release
	end

Route115_Falkner_2:
	msgbox Route115_Falkner_Text_3
	applymovement 24, route115falknerlookAway
	release
	end


Route115_Falkner_Pidgeotto::
	lock
	faceplayer
	playmoncry SPECIES_PIDGEOTTO, CRY_MODE_NORMAL
	msgbox Route115_Falkner_Pidgeotto_Text_0
	waitmoncry
	applymovement 25, route115falknerPidgeotto
	release
	end


route115falknerPidgeotto:
	face_player
	step_end

route115falknerlookAway:
	face_left
	step_end

Route115_Falkner_Text_0:
	.string "???: The breeze is really nice here isn't\n"
	.string "it, Pidgeotto?$"

Route115_Falkner_Text_1:
	.string "I'm Falkner from Johto. I came here to\n"
	.string "Hoenn to train with my bird Pokémon.$"

Route115_Falkner_Text_2:
	.string "I see the same spark in your eyes that\n"
	.string "I have for Pokémon battles. How about\l"
	.string "we test our skills in an unofficial\l"
	.string "match?$"

Route115_Falkner_Text_3:
	.string "I see. Well, I hope we can battle some\n"
	.string "other time.$"

Route115_Falkner_Text_4:
	.string "Excelent, I promise to give you a battle\n"
	.string "that soars as high as my bird Pokémon.\l"
	.string "Let's see if you can withstand the\l"
	.string "grace and power of the skies!$"

Route115_Falkner_Text_5:
	.string "Spectacular! You clipped our wings!$"

Route115_Falkner_Text_6:
	.string "I was right about you, that spark in\n"
	.string "your eyes is the same I saw when I\l"
	.string "faced another young trainer just like\l"
	.string "you some time ago.$"

Route115_Falkner_Text_7:
	.string "I will keep travelling this land more, I\n"
	.string "hope to battle you again another time.$"

Route115_Falkner_Text_8:
	.string "Take this as a thank you gift for our\n"
	.string "battle.$"

Route115_Falkner_Text_9:
	.string "Good bye for now.$"

Route115_Falkner_Pidgeotto_Text_0:
	.string "Pidgeotto: Pidgeo!$"
