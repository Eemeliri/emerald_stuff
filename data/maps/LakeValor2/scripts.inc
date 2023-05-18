LakeValor2_MapScripts::
	.byte 0


magikarps::
	lockall
	playmoncry SPECIES_MAGIKARP, CRY_MODE_FAINT
	releaseall
	end


anabelSwapflag2::
	lockall
	msgbox anabelSwapflag2_Text_0
	clearflag FLAG_LAKE_OF_VALOR
	warp MAP_ROUTE103, 8, 2
	releaseall
	end


gGrunt_1::
	trainerbattle_single TRAINER_GGRUNT_1, gGrunt_1_Text_0, gGrunt_1_Text_1
	msgbox gGrunt_1_Text_2, MSGBOX_AUTOCLOSE
	end


gGrunt_2::
	trainerbattle_single TRAINER_GGRUNT_2, gGrunt_1_Text_0, gGrunt_1_Text_1
	msgbox gGrunt_1_Text_2, MSGBOX_AUTOCLOSE
	end


gGrunt_3::
	trainerbattle_single TRAINER_GGRUNT_3, gGrunt_1_Text_0, gGrunt_1_Text_1
	msgbox gGrunt_1_Text_2, MSGBOX_AUTOCLOSE
	end


gCommanderSaturn::
	trainerbattle_single TRAINER_GSATURN_1, gGrunt_1_Text_0, gGrunt_1_Text_1
	msgbox gGrunt_1_Text_2, MSGBOX_AUTOCLOSE
	end


anabelSwapflag2_Text_0:
	.string "flag toggling off.$"

gGrunt_1_Text_0:
	.string "todo1$"

gGrunt_1_Text_1:
	.string "todo2$"

gGrunt_1_Text_2:
	.string "I'll beat you next time$"
