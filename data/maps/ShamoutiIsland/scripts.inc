ShamoutiIsland_MapScripts::
	.byte 0


ShamotiSlowbro::
	bufferspeciesname 0, SPECIES_SLOWKING
	lock
	faceplayer
	msgbox ShamotiSlowbro_Text_0
	release
	end


ShamotiSlowbro_Text_0:
	.string "It's quite chilly here isn't it? I could\n"
	.string "use a pair of pants...$"
