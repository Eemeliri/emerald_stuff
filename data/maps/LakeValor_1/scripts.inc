.set LOCALID_RIVAL, 2

LakeValor_1_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, return_to_reality
	map_script MAP_SCRIPT_ON_TRANSITION, lakeOfValor_OnLoad
	.byte 0

return_to_reality::
	map_script_2 VAR_LAKE_OF_VALOR_STATE, 1, triggerThanks
	.2byte 0

lakeOfValor_OnLoad::
	call Common_EventScript_SetupRivalGfxId
	end

lakeOfValor_EventScript_Rival::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, lakeOfValor_EventScript_RivalMay
	goto_if_eq VAR_RESULT, FEMALE, lakeOfValor_EventScript_RivalBrendan
	end

lakeOfValor_EventScript_RivalMay::
	msgbox lakeOfValor_Text_MaylakeOfValorPokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_LYRA, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox lakeOfValor_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, lakeOfValor_EventScript_StartMayBattleTreecko
	case 1, lakeOfValor_EventScript_StartMayBattleTorchic
	case 2, lakeOfValor_EventScript_StartMayBattleMudkip
	end

lakeOfValor_EventScript_RivalBrendan::
	msgbox lakeOfValor_Text_BrendanlakeOfValorPokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox lakeOfValor_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, lakeOfValor_EventScript_StartBrendanBattleTreecko
	case 1, lakeOfValor_EventScript_StartBrendanBattleTorchic
	case 2, lakeOfValor_EventScript_StartBrendanBattleMudkip
	end

lakeOfValor_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, lakeOfValor_Text_MayDefeated
	goto lakeOfValor_EventScript_AfterMayBattle
	end

lakeOfValor_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, lakeOfValor_Text_MayDefeated
	goto lakeOfValor_EventScript_AfterMayBattle
	end

lakeOfValor_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, lakeOfValor_Text_MayDefeated
	goto lakeOfValor_EventScript_AfterMayBattle
	end

lakeOfValor_EventScript_StartBrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, lakeOfValor_Text_BrendanDefeated
	goto lakeOfValor_EventScript_AfterBrendanBattle
	end

lakeOfValor_EventScript_StartBrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, lakeOfValor_Text_BrendanDefeated
	goto lakeOfValor_EventScript_AfterBrendanBattle
	end

lakeOfValor_EventScript_StartBrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, lakeOfValor_Text_BrendanDefeated
	goto lakeOfValor_EventScript_AfterBrendanBattle
	end

lakeOfValor_EventScript_AfterMayBattle::
	msgbox lakeOfValor_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto lakeOfValor_EventScript_RivalExit
	end

lakeOfValor_EventScript_AfterBrendanBattle::
	msgbox lakeOfValor_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto lakeOfValor_EventScript_RivalExit
	end

lakeOfValor_EventScript_RivalExit::
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, lakeOfValor_EventScript_RivalExitFacingSouth
	case DIR_NORTH, lakeOfValor_EventScript_RivalExitFacingSouth
	case DIR_WEST, lakeOfValor_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, lakeOfValor_EventScript_RivalExitFacingEastOrWest
	end

lakeOfValor_EventScript_RivalExitFacingEastOrWest::
	applymovement LOCALID_RIVAL, lakeOfValor_Movement_RivalExit1
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	goto lakeOfValor_EventScript_RivalEnd
	end

lakeOfValor_EventScript_RivalExitFacingSouth::
	applymovement LOCALID_RIVAL, lakeOfValor_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	goto lakeOfValor_EventScript_RivalEnd
	end

lakeOfValor_EventScript_RivalEnd::
	removeobject LOCALID_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end


lakeOfValor_Movement_RivalExitFacingNorth1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

lakeOfValor_Movement_RivalExit1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

lakeOfValor_Movement_RivalExit2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

lakeOfValor_Text_MaylakeOfValorPokemon:
	.string "May: Let's see… The Pokémon found\n"
	.string "on Lake of Valor include…$"

lakeOfValor_Text_MayLetsBattle:
	.string "Oh, hi, {PLAYER}{KUN}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a Pokémon as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a Trainer is like.$"

lakeOfValor_Text_MayDefeated:
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"

lakeOfValor_Text_MayTimeToHeadBack:
	.string "May: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that Pokémon,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of Pokémon easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the Lab.$"

lakeOfValor_Text_BrendanlakeOfValorPokemon:
	.string "Brendan: Okay, so it's this one and\n"
	.string "that one that live on Lake of Valor…$"

lakeOfValor_Text_BrendanLetsBattle:
	.string "Hey, it's {PLAYER}!\p"
	.string "…Oh, yeah, Dad gave you a Pokémon.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a Trainer's\n"
	.string "about!$"

lakeOfValor_Text_BrendanDefeated:
	.string "Huh, {PLAYER}, you're not too shabby.$"

lakeOfValor_Text_BrendanTimeToHeadBack:
	.string "Brendan: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your Pokémon already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any Pokémon with ease.\p"
	.string "We should head back to the Lab.$"


anabelSwapflag::
	msgbox anabelSwapflag_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq anabelSwapflag_1
	clearflag FLAG_LAKE_OF_VALOR
	return

anabelSwapflag_1:
	setflag FLAG_LAKE_OF_VALOR
	return


triggerThanks::
	lockall
	delay 30
	msgbox triggerThanks_Text_0
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, confusedPlayer
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 60
	msgbox triggerThanks_Text_1
	delay 120
	msgbox triggerThanks_Text_2
	giveitem ITEM_GRASS_MEMORY
	setvar VAR_LAKE_OF_VALOR_STATE, 2
	setvar VAR_VERITY_CAVERN_STATE, 1
	releaseall
	end


confusedPlayer:
	emote_question_mark
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	delay_16
	step_end

anabelSwapflag_Text_0:
	.string "Toggle flag?$"

triggerThanks_Text_0:
	.string "T--nk y-u...$"

triggerThanks_Text_1:
	.string "...The voice fades away. It seems like\n"
	.string "the attack was an illusion, a memory\l"
	.string "perhaps?$"

triggerThanks_Text_2:
	.string "There seems to be something in front of\n"
	.string "you.$"
