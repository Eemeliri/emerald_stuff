PetalburgWoodsDepths_MapScripts::
	.byte 0


phantumpvillager::
	bufferspeciesname 0, SPECIES_PHANTUMP
	lock
	playmoncry SPECIES_PHANTUMP, CRY_MODE_NORMAL
	msgbox phantumpvillager_Text_0
	waitmoncry
	release
	end


villagegirlwithphantump::
	lock
	msgbox villagegirlwithphantump_Text_0
	waitmessage
	playmoncry SPECIES_PHANTUMP, CRY_MODE_WEAK
	msgbox villagegirlwithphantump_Text_1
	waitmoncry
	release
	end


villageMan::
	lock
	faceplayer
	msgbox villageMan_Text_0
	release
	end


villageLady::
	lock
	faceplayer
	msgbox villageLady_Text_0
	release
	end


oldShrine::
	lock
	msgbox oldShrine_Text_0
	release
	end


shrineSign::
	msgbox shrineSign_Text_0, MSGBOX_SIGN
	end


worriedOldManFarfetchd::
	lock
	faceplayer
	msgbox worriedOldManFarfetchd_Text_0
	msgbox worriedOldManFarfetchd_Text_1
	release
	end


petalburgFarfetchd::
	bufferspeciesname 0, SPECIES_FARFETCHD
	lock
	faceplayer
	msgbox petalburgFarfetchd_Text_0
	setflag FLAG_HIDE_FARFETCHD_MAN
	release
	end


gruntwoods::
	lock
	faceplayer
	msgbox gruntwoods_Text_0
	release
	end


phantumpvillager_Text_0:
	.string "Phantoo!$"

villagegirlwithphantump_Text_0:
	.string "Come on phantump, sit!$"

villagegirlwithphantump_Text_1:
	.string "Phantoo...$"

villageMan_Text_0:
	.string "Our village doesn't offer much, in fact\n"
	.string "we don't even have a name for it. Feel\l"
	.string "free to take a look around nonetheless.$"

villageLady_Text_0:
	.string "Oh a visitor? We don't see many\n"
	.string "travellers around this part of the\l"
	.string "woods, many just pass through the\l"
	.string "Petalburg Woods without stopping by.$"

oldShrine_Text_0:
	.string "It seems to be an old shrine, however it\n"
	.string "hasn't been maintained in a while...$"

shrineSign_Text_0:
	.string "{UP_ARROW} Timekeeper's shrine$"

worriedOldManFarfetchd_Text_0:
	.string "Oh what am I to do... Oh, excuse me! Have\n"
	.string "you seen my dear Farfetch'd? We we're\l"
	.string "just on the way back to the village, but\l"
	.string "she disappeared along the way.$"

worriedOldManFarfetchd_Text_1:
	.string "Could I ask you to look for her?$"

petalburgFarfetchd_Text_0:
	.string "Farfetchd....$"

gruntwoods_Text_0:
	.string "What do you want?$"
