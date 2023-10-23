PetalburgWoods_House2_MapScripts::
	.byte 0


farfetchinhouse::
	bufferspeciesname 0, SPECIES_FARFETCHD
	lock
	faceplayer
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox farfetchinhouse_Text_0
	waitmoncry
	release
	end


farfetchinhouse_Text_0:
	.string "Farfetch'd!$"
