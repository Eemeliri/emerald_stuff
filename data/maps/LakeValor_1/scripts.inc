LakeValor_1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeValor_1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

LakeValor_1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto LakeOfValorOnTransition
	return


LakeOfValorOnTransition::
	goto_if_set FLAG_LAKE_OF_VALOR, LakeOfValorOnTransition_1
	return

LakeOfValorOnTransition_1:
	setmaplayoutindex LAYOUT_LAKE_VALOR2
	return


anabelSwapflag::
	msgbox anabelSwapflag_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq anabelSwapflag_1
	clearflag FLAG_LAKE_OF_VALOR
	return

anabelSwapflag_1:
	setflag FLAG_LAKE_OF_VALOR
	return


anabelSwapflag_Text_0:
	.string "Toggle flag?$"
