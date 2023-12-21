BrawlyDojoTrainingRoom_MapScripts::
	.byte 0


dojoFexpert::
	lock
	faceplayer
	msgbox dojoFexpert_Text_0
	release
	end


dojoTrainer::
	msgbox dojoTrainer_Text_0, MSGBOX_AUTOCLOSE
	end


dojoFexpert_Text_0:
	.string "Training yourself mentally and\n"
	.string "physically is as important as training\l"
	.string "your Pokémon. Tough challenges cannot\l"
	.string "be faced with weak body and mind.$"

dojoTrainer_Text_0:
	.string "The student is meditating, it would be\n"
	.string "rude to disturb them.$"
