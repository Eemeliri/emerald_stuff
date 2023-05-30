SouthernWilds_MapScripts::
	.byte 0


wallPuzzle1::
	lock
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, SLIDING_PUZZLE_KABUTO
	setvar VAR_0x8005, FALSE
	special DoSlidingPuzzle
	fadescreen FADE_FROM_BLACK
	waitstate
	goto_if_eq VAR_RESULT, TRUE, EventScript_Puzzle1Solved
	release
	return


EventScript_Puzzle1Solved::
	msgbox EventScript_Puzzle1Solved_Text_0
	release
	return


EventScript_Puzzle1Solved_Text_0:
	.string "You did it!$"
