BrawlyDojoTrainingRoom_MapScripts::
	.byte 0


dojoFexpert::
	lock
	faceplayer
	msgbox dojoFexpert_Text_0
	goto_if_unset FLAG_RECEIVED_FOCUS_BAND, dojoFexpert_2
dojoFexpert_1:
	release
	end

dojoFexpert_2:
	msgbox dojoFexpert_Text_1
	giveitem ITEM_FOCUS_BAND
	setflag FLAG_RECEIVED_FOCUS_BAND
	goto dojoFexpert_1


dojoTrainer::
	msgbox dojoTrainer_Text_0, MSGBOX_AUTOCLOSE
	end


dojoFexpert_Text_0:
	.string "Training yourself mentally and\n"
	.string "physically is as important as training\l"
	.string "your Pokémon. Tough challenges cannot\l"
	.string "be faced with weak body and mind.$"

dojoFexpert_Text_1:
	.string "Perhaps this will help you focus on your\n"
	.string "training.$"

dojoTrainer_Text_0:
	.string "The student is meditating, it would be\n"
	.string "rude to disturb them.$"
