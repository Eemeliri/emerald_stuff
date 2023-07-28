VajraPyramid_MapScripts::
	.byte 0


pyramidRuinManiac::
	lock
	faceplayer
	msgbox pyramidRuinManiac_Text_0
	release
	end


vajrapyramidsign::
	special getPartyLeadMonWeight
	compare VAR_RESULT, 0
	goto_if_eq vajrapyramidsign_2
	compare VAR_RESULT, 100
	goto_if_le vajrapyramidsign_3
	msgbox vajrapyramidsign_Text_2
vajrapyramidsign_1:
	msgbox vajrapyramidsign_Text_3, MSGBOX_SIGN
	end

vajrapyramidsign_2:
	msgbox vajrapyramidsign_Text_0
	goto vajrapyramidsign_1

vajrapyramidsign_3:
	msgbox vajrapyramidsign_Text_1
	goto vajrapyramidsign_1


pyramidRuinManiac_Text_0:
	.string "Are you heading inside? You should take\n"
	.string "care, there are traps laid down for\l"
	.string "intruders, and lower levels are filled\l"
	.string "with water. Always remember to bring an\l"
	.string "escape rope!$"

vajrapyramidsign_Text_0:
	.string "Lead mon weight is invalid$"

vajrapyramidsign_Text_1:
	.string "Lead mon weight is less than 101$"

vajrapyramidsign_Text_2:
	.string "lead mon weight is over 100$"

vajrapyramidsign_Text_3:
	.string "Vajra Pyramid, crown jewel of the\n"
	.string "desert and resting place of the royal\l"
	.string "ancestors.$"
