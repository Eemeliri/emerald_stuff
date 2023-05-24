DistortionWorld_MapScripts::
	.byte 0


teleportationStone::
	lock
	msgbox teleportationStone_Text_0
	msgbox teleportationStone_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq teleportationStone_2
teleportationStone_1:
	release
	end

teleportationStone_2:
	warpteleport MAP_ROUTE101, 15, 24, 1
	goto teleportationStone_1


teleportationStone_Text_0:
	.string "The stone hums with energy, perhaps it\n"
	.string "can take you back to your world?$"

teleportationStone_Text_1:
	.string "Touch the stone?$"
