MirageSpot_Ash_A_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MirageSpot_Ash_A_OnResume
	.byte 0

MirageSpot_Ash_A_OnResume:
	setstepcallback STEP_CB_ASH
	end
