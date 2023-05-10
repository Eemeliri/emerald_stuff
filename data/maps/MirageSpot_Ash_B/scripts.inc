MirageSpot_Ash_B_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MirageSpot_Ash_B_OnResume
	.byte 0

MirageSpot_Ash_B_OnResume:
	setstepcallback STEP_CB_ASH
	end
