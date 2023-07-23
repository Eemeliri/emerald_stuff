VajraPyramid_MapScripts::
	.byte 0


pyramidRuinManiac::
	lock
	faceplayer
	msgbox pyramidRuinManiac_Text_0
	release
	end


vajrapyramidsign::
	msgbox vajrapyramidsign_Text_0, MSGBOX_SIGN
	end


pyramidRuinManiac_Text_0:
	.string "Are you heading inside? You should take\n"
	.string "care, there are traps laid down for\l"
	.string "intruders, and lower levels are filled\l"
	.string "with water. Always remember to bring an\l"
	.string "escape rope!$"

vajrapyramidsign_Text_0:
	.string "Vajra Pyramid, crown jewel of the\n"
	.string "desert and resting place of the royal\l"
	.string "ancestors.$"
