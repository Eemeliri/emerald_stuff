SandpitSW::
	lockall
	delay 20
	playse SE_ESCALATOR
	applymovement OBJ_EVENT_ID_PLAYER, spinNE
	delay 30
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_VAJRA_DESERT_TUNNELS
	waitstate
	end


SandpitSE::
	lockall
	delay 20
	playse SE_ESCALATOR
	applymovement OBJ_EVENT_ID_PLAYER, spinNW
	delay 30
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_VAJRA_DESERT_TUNNELS
	waitstate
	end


SandpitNE::
	lockall
	delay 20
	playse SE_ESCALATOR
	applymovement OBJ_EVENT_ID_PLAYER, spinSW
	delay 30
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_VAJRA_DESERT_TUNNELS
	waitstate
	end


SandpitNW::
	lockall
	delay 20
	playse SE_ESCALATOR
	applymovement OBJ_EVENT_ID_PLAYER, spinSE
	delay 30
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_VAJRA_DESERT_TUNNELS
	waitstate
	end


SandpitWest::
	lockall
	delay 20
	playse SE_ESCALATOR
	applymovement OBJ_EVENT_ID_PLAYER, spinEast
	delay 30
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_VAJRA_DESERT_TUNNELS
	waitstate
	end


SandpitEast::
	lockall
	delay 20
	playse SE_ESCALATOR
	applymovement OBJ_EVENT_ID_PLAYER, spinWest
	delay 30
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_VAJRA_DESERT_TUNNELS
	waitstate
	end


spinWest:
	walk_left
	walk_in_place_fast_down
	walk_in_place_fast_right
	walk_in_place_fast_up
	walk_in_place_faster_left
	walk_in_place_fast_down
	step_end

spinEast:
	walk_right
	walk_in_place_fast_down
	walk_in_place_fast_right
	walk_in_place_fast_up
	walk_in_place_faster_left
	walk_in_place_fast_down
	step_end

spinNW:
	walk_diag_northwest
	walk_in_place_fast_down
	walk_in_place_fast_right
	walk_in_place_fast_up
	walk_in_place_faster_left
	walk_in_place_fast_down
	step_end

spinNE:
	walk_diag_northeast
	walk_in_place_fast_down
	walk_in_place_fast_right
	walk_in_place_fast_up
	walk_in_place_faster_left
	walk_in_place_fast_down
	step_end

spinSE:
	walk_diag_southeast
	walk_in_place_fast_down
	walk_in_place_fast_right
	walk_in_place_fast_up
	walk_in_place_faster_left
	walk_in_place_fast_down
	step_end

spinSW:
	walk_diag_southwest
	walk_in_place_fast_down
	walk_in_place_fast_right
	walk_in_place_fast_up
	walk_in_place_faster_left
	walk_in_place_fast_down
	step_end
