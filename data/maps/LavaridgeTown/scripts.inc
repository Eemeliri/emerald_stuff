
.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_RIVAL, 11, 9
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_BlackBelt:: @ 8211125
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM75, LavaridgeTown_ReceivedSwordsDance
	msgbox LavaridgeTown_Text_DanceAndSoul, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LavaridgeTown_EventScript_Yes
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_EventScript_No
	end

LavaridgeTown_EventScript_No::
	msgbox LavaridgeTown_Text_SoSad, MSGBOX_DEFAULT
	giveitem ITEM_TM75
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM75
	goto LavaridgeTown_ReceivedSwordsDance
	release
	end

LavaridgeTown_ReceivedSwordsDance::
	msgbox LavaridgeTown_Text_SuhwordsDance, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_Yes::
	msgbox LavaridgeTown_Text_GoodKid, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "May: {PLAYER}{KUN}! Long time no see!\p"
	.string "Oh? While I visited the hot springs,\n"
	.string "you got the Lavaridge Gym Badge.\p"
	.string "You must have collected\n"
	.string "good Pokémon…\l"
	.string "No, I believe you raised some.\p"
	.string "I guess it would be okay for you to\n"
	.string "have this.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "May: With those Go-Goggles, you'll\n"
	.string "have no trouble getting through the\l"
	.string "desert near Route 111.\p"
	.string "But, wow, {PLAYER}{KUN}…\n"
	.string "Challenging Gyms…\p"
	.string "You're trying hard because you don't\n"
	.string "want to lose to me, I bet!\p"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
	.string "your dad in Petalburg Gym.\p"
	.string "See you again!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "Brendan: {PLAYER}, hey, it's been a while.\n"
	.string "How's it going?\p"
	.string "Hmm…\n"
	.string "That's a decent collection of Badges.\p"
	.string "All right, then.\n"
	.string "You may as well have this.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "Brendan: Keep those with you if you're\n"
	.string "planning on going into that desert near\l"
	.string "Route 111.\p"
	.string "There should be some Pokémon that\n"
	.string "are exclusively desert-dwellers.\l"
	.string "You might look around for those.\p"
	.string "As for me…\n"
	.string "I'm considering challenging Norman,\l"
	.string "the Gym Leader of Petalburg.\p"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
	.string "he really is tough.\p"
	.string "See you around!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "I have here an Egg.\p"
	.string "I'd hoped to hatch it by covering it in\n"
	.string "hot sand by the hot springs.\l"
	.string "But that doesn't seem to be enough…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with Pokémon and\l"
	.string "carried about.\p"
	.string "You are a Trainer, yes?\n"
	.string "And your Pokémon radiate vitality.\p"
	.string "So, what say you?\n"
	.string "Will you take this Egg to hatch?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here Egg!$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} received the Egg.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Oh? You've too many Pokémon.\n"
	.string "There's no room for this Egg…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this Egg, I will be here.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "Every so often, an Egg will be found at\n"
	.string "the Pokémon Day Care.\p"
	.string "Or at least that's how the rumor goes.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "We draw as much hot water as we need,\n"
	.string "and yet the hot springs never run dry.\p"
	.string "Isn't it magical?\p"
	.string "These hot springs appear near active\n"
	.string "volcanoes. Veins of water under the\l"
	.string "ground are heated by magma to well up\l"
	.string "as hot springs.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Being buried in this hot sand is…\n"
	.string "Sigh…\p"
	.string "So warm and heavenly…\p"
	.string "Eh? Gyaah! Ouch!\p"
	.string "A Pokémon nipped my backside!$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Oh, you like hot springs, do you?\p"
	.string "That's surprising for one as young\n"
	.string "as you.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "I bathe in the hot springs every day.\p"
	.string "I want to become a beautiful and strong\n"
	.string "Gym Leader like Flannery.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "If people put Pokémon in hot springs,\n"
	.string "it might be seriously strange.\p"
	.string "Why, it might be an electric bath, or\n"
	.string "a bubble bath, or even a lava bath…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "They're claiming that these hot springs\n"
	.string "are good for calming nervous tension,\l"
	.string "relieving aching muscles, solving\l"
	.string "romantic problems, and attracting\l"
	.string "money…$"

LavaridgeTown_Text_TownSign:
	.string "Lavaridge Town\p"
	.string "“Pokémon Center Hot Springs\n"
	.string "An excellent place for relaxing!”$"

LavaridgeTown_Text_GymSign:
	.string "Lavaridge Town Pokémon Gym\n"
	.string "Leader: Flannery\l"
	.string "“One with a fiery passion that burns!”$"

LavaridgeTown_Text_HerbShopSign:
	.string "Pokémon Herb Shop\n"
	.string "“Bitter taste--better cure!”$"

LavaridgeTown_Text_DanceAndSoul:
	.string "Dance and soul make power!\p"
	.string "Soul is way of karate for me!\p"
	.string "You understand, yes?$"

LavaridgeTown_Text_GoodKid:
	.string "OK! OK!\n"
	.string "You good kid!$"

LavaridgeTown_Text_SoSad:
	.string "Oh...\n"
	.string "I so sad and wretched...\p"
	.string "You take this and you understand\n"
	.string "way of karate of me, fool Trainer!$"

LavaridgeTown_Text_SuhwordsDance:
	.string "Suh-words Dance!$"

BlainePostgame::
	lockall
	faceplayer
	goto_if_set FLAG_RECEIVED_OLD_SEA_MAP, BlaineReceivedMap
	msgbox BlainePostgame_Text_0
	msgbox BlainePostgame_Text_1
	msgbox BlainePostgame_Text_2
	msgbox BlainePostgame_Text_3
	msgbox BlainePostgame_Text_4, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, BlainePostgame_3
	case NO, BlainePostgame_4
	case MULTI_B_PRESSED, BlainePostgame_5
BlainePostgame_1:
	msgbox BlainePostgame_Text_8
	msgbox BlainePostgame_Text_9
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	msgbox BlainePostgame_Text_10
	msgbox BlainePostgame_Text_11
	releaseall
	end

BlainePostgame_3:
	msgbox BlainePostgame_Text_5
	waitmessage
	trainerbattle_no_intro TRAINER_POSTGAME_BLAINE, BlainePostgame_Text_6
	goto BlainePostgame_1

BlainePostgame_4:
	msgbox BlainePostgame_Text_7
	releaseall
	end

BlainePostgame_5:
	msgbox BlainePostgame_Text_7
	releaseall
	end


BlaineReceivedMap::
	msgbox BlaineReceivedMap_Text_0
	release
	end


BlainePostgame_Text_0:
	.string "Well if it isn't the new champion of\n"
	.string "Hoenn, {PLAYER}!$"

BlainePostgame_Text_1:
	.string "My name is Blaine, I'm a gym leader from\n"
	.string "Kanto region.$"

BlainePostgame_Text_2:
	.string "I heard Lavaridge has some of the\n"
	.string "finest hot springs in the world, so I\l"
	.string "came to soothe these old aching bones.$"

BlainePostgame_Text_3:
	.string "However now that you are here, I'm on\n"
	.string "the mood for something better than hot\l"
	.string "springs, how about we battle instead?\l"
	.string "It's been a while since I got to face a\l"
	.string "worthy trainer.$"

BlainePostgame_Text_4:
	.string "Are you up for a heated battle?$"

BlainePostgame_Text_5:
	.string "Hah! Don't except to cool me just\n"
	.string "because you're the Champion, hope you\l"
	.string "have a Burn Heal on hand!$"

BlainePostgame_Text_6:
	.string "Scorching! You've burned me to crisp!$"

BlainePostgame_Text_7:
	.string "Not feeling the heat? Perhaps another\n"
	.string "time then.$"

BlainePostgame_Text_8:
	.string "That was a truly blazingly hot battle!\n"
	.string "You've invigorated my spirit, young\l"
	.string "champion.$"

BlainePostgame_Text_9:
	.string "How about you take this old map as a\n"
	.string "reward for besting me, It hides a secret\l"
	.string "worthy of a champion.$"

BlainePostgame_Text_10:
	.string "I hear Lilycove city's port has a fellow\n"
	.string "who can help you track down the island\l"
	.string "marked on this map.$"

BlainePostgame_Text_11:
	.string "I'm going to head to the Pokémon World\n"
	.string "Tournament after I've had enough of\l"
	.string "the hot springs here, perhaps we can\l"
	.string "have another heated battle there!$"

BlaineReceivedMap_Text_0:
	.string "Hey champion! Found the island marked\n"
	.string "in the map yet?$"
