.set LOCALID_FOSSIL_SCIENTIST, 5

RustboroCity_DevonCorp_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
	.byte 0

RustboroCity_DevonCorp_2F_OnTransition:
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	end

RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
	return

RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_BallScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist:: 
	lock
	faceplayer
	compare VAR_FOSSIL_RESURRECTION_STATE, 2
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
	specialvar VAR_RESULT, DoesPlayerHaveFossil
	compare VAR_RESULT, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_NoticeFossil
	release
	end

RustboroCity_DevonCorp_2F_EventScript_NoticeFossil::
	closemessage
	playse SE_PIN
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
	waitmovement 0
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
	msgbox RustboroCity_DevonCorp_2F_Text_FossilsPickOne, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special Bag_ChooseItem
	waitstate
	specialvar VAR_RESULT, IsItemFossil
	compare VAR_RESULT, FALSE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ThatsNotAFossil
	special FossilToSpecies
	bufferitemname 0, VAR_ITEM_ID
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
	removeitem VAR_ITEM_ID
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
	copyvar VAR_WHICH_FOSSIL_REVIVED, VAR_ITEM_ID
	release
	end

RustboroCity_DevonCorp_2F_EventScript_ThatsNotAFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_ThatsNotAFossil, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8006 is Pokemon species to restore
@ VAR_0x8008 is the fossil that was chosen for restoration
RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
	copyvar VAR_0x8008, VAR_WHICH_FOSSIL_REVIVED
	special FossilToSpecies
	bufferspeciesname 1, VAR_0x8006
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
	copyvar VAR_TEMP_1, VAR_0x8006
	givemon VAR_0x8006, 30
	compare VAR_RESULT, 0
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilParty
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilParty:: @ 8211A6E
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossil
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ReceiveFossilPC:: @ 8211A96
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_TransferFossilToPC
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_TransferFossilToPC
	end

RustboroCity_DevonCorp_2F_EventScript_TransferFossilToPC:: @ 8211AB9
	call Common_EventScript_TransferredToPC
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossil
	end

RustboroCity_DevonCorp_2F_EventScript_ReceivedFossilFanfare:: @ 8211AC4
	bufferspeciesname 1, VAR_0x8006
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname 0, VAR_0x8006
	return

RustboroCity_DevonCorp_2F_EventScript_FinishReceivingFossil:: @ 8211AD7
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	release
	end


RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
	release
	end

RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
	lock
	faceplayer
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
	.string "We're developing a device for talking\n"
	.string "with Pokémon.\p"
	.string "But we haven't had much success…$"

RustboroCity_DevonCorp_2F_Text_FossilsPickOne: @ 8212092
	.string "Which fossil would you like to\n"
	.string "regenerate?$"

RustboroCity_DevonCorp_2F_Text_ThatsNotAFossil:
	.string "Come now, that's not a fossil!$"

RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
	.string "I'm developing new kinds of\n"
	.string "Poké Balls…\p"
	.string "But I haven't made much headway…$"

RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
	.string "We finally made new kinds of\n"
	.string "Poké Balls!\p"
	.string "The Repeat Ball makes it easier to\n"
	.string "catch Pokémon you've caught before.\p"
	.string "The Timer Ball gets better at catching\n"
	.string "Pokémon the longer a battle runs.\p"
	.string "Both are proudly developed by\n"
	.string "the Devon Corporation.\p"
	.string "Please give them a try!$"

RustboroCity_DevonCorp_2F_Text_IMadePokenav:
	.string "I made the Pokénav!\p"
	.string "As an engineer, I feel blessed to have\n"
	.string "made something so great!$"

RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
	.string "Oh, wow!\n"
	.string "That's a Pokénav!\p"
	.string "It came about as a result of our\n"
	.string "President's desire to learn about\l"
	.string "the feelings of Pokémon.$"

RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
	.string "I'm trying to develop a device that\n"
	.string "visually reproduces the dreams of\l"
	.string "Pokémon…\p"
	.string "But it's not going well.$"

RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
	.string "I've been trying to develop a device\n"
	.string "that resurrects Pokémon from fossils…\p"
	.string "And, it's working!$"

RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
	.string "Wait! That thing you have there…\n"
	.string "Is that a Pokémon fossil?\p"
	.string "Would you like to bring that Pokémon\n"
	.string "back to life?\p"
	.string "I can with my newly developed\n"
	.string "Fossil Regenerator.$"

RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
	.string "Oh, is that so?\p"
	.string "Devon's technological expertise\n"
	.string "is outstanding, I tell you.$"

RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
	.string "Oh, now that's a surprise!\n"
	.string "You have not one, but two, fossils?\p"
	.string "Unfortunately, my machine can only\n"
	.string "regenerate one Pokémon at a time.\p"
	.string "Would you like to pick one of your\n"
	.string "fossils for regeneration?$"

RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
	.string "Excellent!\n"
	.string "Let's do this right away.\p"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
	.string "the Devon Researcher.$"

RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
	.string "The Fossil Regenerator, which I made,\n"
	.string "is incredible.\p"
	.string "But it has one drawback--it takes\n"
	.string "a long time to work.\p"
	.string "So, uh… How about you go for a stroll\n"
	.string "and look around for a while?$"

RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
	.string "Thanks for waiting!\p"
	.string "Your fossilized Pokémon has been\n"
	.string "brought back to life!\p"
	.string "The fossil was an ancient Pokémon.\n"
	.string "{STR_VAR_2}, it was!$"

RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
	.string "{PLAYER} received {STR_VAR_2} from\n"
	.string "the Devon Researcher.$"

@ Unused
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
	.string "Uh-oh, you've got too many Pokémon.\n"
	.string "You have no room for this one.$"

RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
	.string "I'm trying to develop a new feature\n"
	.string "for the Pokénav…\p"
	.string "But it's not going well.$"

RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
	.string "Well, now what shall I work on\n"
	.string "developing next?\p"
	.string "Our company allows us to make our\n"
	.string "inspirations into reality.\p"
	.string "One couldn't ask for a better\n"
	.string "environment as an engineer.$"

dreamResearcherQuest::
	lock
	faceplayer
	returnqueststate QUEST_9
	switch VAR_RESULT
	case 1, dreamResearcherQuest_3
	case 2, dreamResearcherQuest_4
	case 4, dreamResearcherQuest_5
dreamResearcherQuest_1:
	release
	end

dreamResearcherQuest_3:
	msgbox dreamResearcherQuest_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq dreamResearcherQuest_6
	msgbox dreamResearcherQuest_Text_2
	goto dreamResearcherQuest_1

dreamResearcherQuest_4:
	msgbox dreamResearcherQuest_Text_3
	setvar 0x8005, SPECIES_ABRA
	special CheckSpecies
	compare VAR_RESULT, TRUE
	goto_if_eq dreamResearcherQuest_9
	msgbox dreamResearcherQuest_Text_12
	goto dreamResearcherQuest_1

dreamResearcherQuest_5:
	msgbox dreamResearcherQuest_Text_13
	goto dreamResearcherQuest_1

dreamResearcherQuest_6:
	msgbox dreamResearcherQuest_Text_1
	startquest QUEST_9
	goto dreamResearcherQuest_1

dreamResearcherQuest_9:
	playse SE_PIN
	applymovement 4, dreamResearchersurprised
	waitse
	waitmovement 4
	msgbox dreamResearcherQuest_Text_4
	fadescreen FADE_TO_BLACK
	msgbox dreamResearcherQuest_Text_5
	waitmessage
	delay 60
	msgbox dreamResearcherQuest_Text_6
	waitbuttonpress
	fadescreen FADE_FROM_BLACK
	msgbox dreamResearcherQuest_Text_7
	msgbox dreamResearcherQuest_Text_8
	playfanfare MUS_OBTAIN_ITEM
	msgbox dreamResearcherQuest_Text_9
	msgbox dreamResearcherQuest_Text_10
	setflag FLAG_SYS_DEXNAV_GET
	waitfanfare
	msgbox dreamResearcherQuest_Text_11
	completequest QUEST_9
	goto dreamResearcherQuest_1


dreamResearchersurprised:
	emote_exclamation_mark
	step_end

dreamResearcherQuest_Text_0:
	.string "I'm trying to develop a new program\n"
	.string "that can analyze dreams of Pokémon.\l"
	.string "However I'm missing a test subject.\l"
	.string "Could you help me find an Abra for my\l"
	.string "research? I can reward you with our\l"
	.string "latest piece of technology, a Dexnav.$"

dreamResearcherQuest_Text_1:
	.string "Many thanks! I think you can find wild\n"
	.string "Abras in Route 116.$"

dreamResearcherQuest_Text_2:
	.string "Oh... That's a shame.$"

dreamResearcherQuest_Text_3:
	.string "Hi again, Any luck finding an Abra?$"

dreamResearcherQuest_Text_4:
	.string "That's it! You found one! Allow me just a\n"
	.string "moment so I can run the tests!$"

dreamResearcherQuest_Text_5:
	.string "You waited while the researcher\n"
	.string "started running tests with the sleepy\l"
	.string "Abra.$"

dreamResearcherQuest_Text_6:
	.string "...Four hours later.$"

dreamResearcherQuest_Text_7:
	.string "It's done, and with great results\n"
	.string "thanks to you! The time just flies by\l"
	.string "when you're working, doesn't it?$"

dreamResearcherQuest_Text_8:
	.string "You can have your Abra back, and here's\n"
	.string "the promised reward.$"

dreamResearcherQuest_Text_9:
	.string "{PLAYER} received a Dexnav.$"

dreamResearcherQuest_Text_10:
	.string "This device allows you to more\n"
	.string "comfortably catch lots of Pokémon!\l"
	.string "It's still in F&F alpha phase, however I\l"
	.string "believe the president would want you to\l"
	.string "have it.$"

dreamResearcherQuest_Text_11:
	.string "I'll continue my research and one day\n"
	.string "hope to be able to enter the dreams of\l"
	.string "Pokémons!$"

dreamResearcherQuest_Text_12:
	.string "Not yet? Take your time, I have hourly\n"
	.string "wage so there's no rush. You can find\l"
	.string "Abras in Route 116.$"

dreamResearcherQuest_Text_13:
	.string "Hi again! My research has been going\n"
	.string "great and we're making great progress\l"
	.string "on the dream research. We still can't\l"
	.string "enter inside dreams, but hopefully\l"
	.string "soon.$"
