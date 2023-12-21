BrawlyDojo_MapScripts::
	.byte 0


megaKickTrainer::
	lock
	msgbox megaKickTrainer_Text_0
	release
	end


megaPunchTrainer::
	lock
	msgbox megaPunchTrainer_Text_0
	release
	end


DojoTourist::
	lock
	faceplayer
	msgbox DojoTourist_Text_0
	release
	end


DojoTrainee::
	lock
	faceplayer
	msgbox DojoTrainee_Text_0
	release
	end


DojoTeacher::
	lock
	faceplayer
	msgbox DojoTeacher_Text_0
	release
	end


megaKickTrainer_Text_0:
	.string "No no, you don't get it, Mega Punch is\n"
	.string "the superior move!$"

megaPunchTrainer_Text_0:
	.string "Fool! Everyone knows Mega Kick is the\n"
	.string "true path to power!$"

DojoTourist_Text_0:
	.string "The doors behind me lead to training\n"
	.string "room and battle arena. I hear the arena\l"
	.string "is still under construction though.$"

DojoTrainee_Text_0:
	.string "If you want to grow stronger, you\n"
	.string "should visit the training room.$"

DojoTeacher_Text_0:
	.string "Ahead is the practice room for\n"
	.string "students, take care not to disturb\l"
	.string "them.$"
