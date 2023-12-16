BrawlyDojoEVRoom2_MapScripts::
	.byte 0


hpEvTrainer::
	lock
	faceplayer
	msgbox hpEvTrainer_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq hpEvTrainer_2
hpEvTrainer_1:
	release
	end

hpEvTrainer_2:
	trainerbattle_no_intro TRAINER_BRAWLYDOJO_HP, hpEvTrainer_Text_1
	goto hpEvTrainer_1


attackEvTrainer::
	lock
	faceplayer
	msgbox attackEvTrainer_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq attackEvTrainer_2
attackEvTrainer_1:
	release
	end

attackEvTrainer_2:
	trainerbattle_no_intro TRAINER_BRAWLYDOJO_ATTACK, hpEvTrainer_Text_1
	goto attackEvTrainer_1


defenseEvTrainer::
	lock
	faceplayer
	msgbox defenseEvTrainer_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq defenseEvTrainer_2
defenseEvTrainer_1:
	release
	end

defenseEvTrainer_2:
	trainerbattle_no_intro TRAINER_BRAWLYDOJO_DEFENSE, hpEvTrainer_Text_1
	goto defenseEvTrainer_1


spatkEvTrainer::
	lock
	faceplayer
	msgbox spatkEvTrainer_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq spatkEvTrainer_2
spatkEvTrainer_1:
	release
	end

spatkEvTrainer_2:
	trainerbattle_no_intro TRAINER_BRAWLYDOJO_SPATK, hpEvTrainer_Text_1
	goto spatkEvTrainer_1


spdefEvTrainer::
	lock
	faceplayer
	msgbox spdefEvTrainer_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq spdefEvTrainer_2
spdefEvTrainer_1:
	release
	end

spdefEvTrainer_2:
	trainerbattle_no_intro TRAINER_BRAWLYDOJO_SPDEF, hpEvTrainer_Text_1
	goto spdefEvTrainer_1


speedEvTrainer::
	lock
	faceplayer
	msgbox speedEvTrainer_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq speedEvTrainer_2
speedEvTrainer_1:
	release
	end

speedEvTrainer_2:
	trainerbattle_no_intro TRAINER_BRAWLYDOJO_SPEED, hpEvTrainer_Text_1
	goto speedEvTrainer_1


expTrainerDojo::
	lock
	faceplayer
	msgbox expTrainerDojo_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq expTrainerDojo_2
expTrainerDojo_1:
	release
	end

expTrainerDojo_2:
	trainerbattle_no_intro TRAINER_BRAWLYDOJO_EXP, expTrainerDojo_Text_1
	msgbox expTrainerDojo_Text_2
	goto_if_set FLAG_IS_CHAMPION, expTrainerDojo_4
	goto_if_set FLAG_BADGE08_GET, expTrainerDojo_5
	goto_if_set FLAG_BADGE07_GET, expTrainerDojo_6
	goto_if_set FLAG_BADGE06_GET, expTrainerDojo_7
	goto_if_set FLAG_BADGE05_GET, expTrainerDojo_8
	goto_if_set FLAG_BADGE04_GET, expTrainerDojo_9
	goto_if_set FLAG_BADGE03_GET, expTrainerDojo_10
	goto_if_set FLAG_BADGE02_GET, expTrainerDojo_11
	goto_if_set FLAG_BADGE01_GET, expTrainerDojo_12
	goto expTrainerDojo_1

expTrainerDojo_4:
	giveitem ITEM_EXP_CANDY_XL, 5
	goto expTrainerDojo_1

expTrainerDojo_5:
	giveitem ITEM_EXP_CANDY_L, 5
	goto expTrainerDojo_1

expTrainerDojo_6:
	giveitem ITEM_EXP_CANDY_L, 2
	goto expTrainerDojo_1

expTrainerDojo_7:
	giveitem ITEM_EXP_CANDY_M, 5
	goto expTrainerDojo_1

expTrainerDojo_8:
	giveitem ITEM_EXP_CANDY_M, 2
	goto expTrainerDojo_1

expTrainerDojo_9:
	giveitem ITEM_EXP_CANDY_S, 5
	goto expTrainerDojo_1

expTrainerDojo_10:
	giveitem ITEM_EXP_CANDY_S, 2
	goto expTrainerDojo_1

expTrainerDojo_11:
	giveitem ITEM_EXP_CANDY_XS, 5
	goto expTrainerDojo_1

expTrainerDojo_12:
	giveitem ITEM_EXP_CANDY_XS, 2
	goto expTrainerDojo_1


nurseJoyEvTraining::
	lock
	faceplayer
	msgbox nurseJoyEvTraining_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq nurseJoyEvTraining_2
nurseJoyEvTraining_1:
	release
	end

nurseJoyEvTraining_2:
	playse MUS_HEAL
	special HealPlayerParty
	waitse
	goto nurseJoyEvTraining_1


PcAccessEvTraining::
	bufferspeciesname 0, SPECIES_PORYGON
	lock
	goto EventScript_PC
	release
	end


hpEvTrainer_Text_0:
	.string "Do you wish to train against my healthy\n"
	.string "team?$"

hpEvTrainer_Text_1:
	.string "Good job.$"

attackEvTrainer_Text_0:
	.string "Do you wish to train against my\n"
	.string "offensive team?$"

defenseEvTrainer_Text_0:
	.string "Do you wish to train against my bulky\n"
	.string "team?$"

spatkEvTrainer_Text_0:
	.string "Do you wish to train against my magical\n"
	.string "team?$"

spdefEvTrainer_Text_0:
	.string "Do you wish to train against my\n"
	.string "resistant team?$"

speedEvTrainer_Text_0:
	.string "Do you wish to train against my fast\n"
	.string "team?$"

expTrainerDojo_Text_0:
	.string "Do you wish to grow your Pokémon\n"
	.string "through battles?$"

expTrainerDojo_Text_1:
	.string "Well done.$"

expTrainerDojo_Text_2:
	.string "Have some candy too.$"

nurseJoyEvTraining_Text_0:
	.string "Welcome to the training room, would you\n"
	.string "like me to heal your Pokémon?$"
