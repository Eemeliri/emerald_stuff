SSAnne_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SSAnne_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SSAnne_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call setAquaMemeberGfxAnne
	return


setAquaMemeberGfxAnne::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_WOMAN_4
	return


ssAnneDoorkeeper::
	return


ssAnneHealerDialogue::
	lock
	faceplayer
	msgbox ssAnneHealerDialogue_Text_0
	release
	end


ssAnneStorageGuard::
	lock
	faceplayer
	msgbox ssAnneStorageGuard_Text_0
	release
	end


ssAnneSailor::
	lock
	faceplayer
	msgbox ssAnneSailor_Text_0
	release
	end


ssAnneKid::
	lock
	faceplayer
	msgbox ssAnneKid_Text_0
	release
	end


ssAnneArtist::
	return


ssAnneGameboykid::
	return


ssAnnegirl1::
	return


ssAnneTrainerBoy::
	return


ssAnneTrainerPsychic::
	return


ssAnneTrainerWoman::
	return


ssAnneWindow::
	return


ssAnneBinoculars::
	return


ssAnneAquaGrunt::
	lock
	faceplayer
	delay 60
	applymovement 10, aquaGruntSpinAnne
	waitmovement 10
	removeobject 10
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MAGMA_MEMBER_F
	addobject 10
	applymovement 10, aquaGruntSpinAnne2
	waitmovement 10
	faceplayer
	msgbox ssAnneAquaGrunt_Text_0
	release
	end


aquaGruntSpinAnne:
	face_up
	delay_2
	face_left
	delay_2
	face_down
	delay_2
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	step_end

aquaGruntSpinAnne2:
	face_down
	delay_2
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	delay_2
	face_right
	delay_2
	step_end

ssAnneHealerDialogue_Text_0:
	.string "You can use this room to rest your\n"
	.string "Pokémon and yourself.$"

ssAnneStorageGuard_Text_0:
	.string "Sorry, but only authorized personel may\n"
	.string "enter the storage.$"

ssAnneSailor_Text_0:
	.string "The banquet is almost over, but there\n"
	.string "are still multiple trainers in here\l"
	.string "looking for a fight.$"

ssAnneKid_Text_0:
	.string "I had lots of fun visiting Hoenn, but I\n"
	.string "can't wait to get back home and play\l"
	.string "with my partner Misdreavus again!$"

ssAnneAquaGrunt_Text_0:
	.string "hi$"
