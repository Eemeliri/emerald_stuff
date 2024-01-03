RuggedRoad_MapScripts::
	.byte 0


RuggedRoad_Lady::
	lock
	faceplayer
	msgbox RuggedRoad_Lady_Text_0
	release
	end


RuggedRoad_BoyRoute102::
	lock
	faceplayer
	msgbox RuggedRoad_BoyRoute102_Text_0
	release
	end


RuggedRoadNorthSign::
	msgbox RuggedRoadNorthSign_Text_0, MSGBOX_SIGN
	end


RuggedRoadSouthSign::
	msgbox RuggedRoadSouthSign_Text_0, MSGBOX_SIGN
	end


RuggedRoadCaveSign::
	msgbox RuggedRoadCaveSign_Text_0, MSGBOX_SIGN
	end


trainerSchooldKidRuggedRoad::
	trainerbattle_single TRAINER_RUGGED_ROAD_SCHOOLKID, trainerSchooldKidRuggedRoad_Text_0, trainerSchooldKidRuggedRoad_Text_1
	msgbox trainerSchooldKidRuggedRoad_Text_2, MSGBOX_AUTOCLOSE
	end


trainerHikerRuggedRoad::
	trainerbattle_single TRAINER_RUGGED_ROAD_HIKER, trainerHikerRuggedRoad_Text_0, trainerHikerRuggedRoad_Text_1
	msgbox trainerHikerRuggedRoad_Text_2, MSGBOX_AUTOCLOSE
	end


trainerPicnickerRuggedRoad::
	trainerbattle_single TRAINER_RUGGED_ROAD_PICNICKER, trainerPicnickerRuggedRoad_Text_0, trainerPicnickerRuggedRoad_Text_1
	msgbox trainerPicnickerRuggedRoad_Text_2, MSGBOX_AUTOCLOSE
	end


trainerCamperRuggedRoad::
	trainerbattle_single TRAINER_RUGGED_ROAD_CAMPER, trainerCamperRuggedRoad_Text_0, trainerCamperRuggedRoad_Text_1
	msgbox trainerCamperRuggedRoad_Text_2, MSGBOX_AUTOCLOSE
	end


RuggedRoad_Lady_Text_0:
	.string "This is a shortcut to Route 102, but\n"
	.string "there's no going back once you start\l"
	.string "hopping down the ledges!$"

RuggedRoad_BoyRoute102_Text_0:
	.string "I wanted to go meet my friend in the\n"
	.string "Rustboro City, but I guess the only way\l"
	.string "is through the Petalburg Woods.$"

RuggedRoadNorthSign_Text_0:
	.string "{DOWN_ARROW} Route 102\n"
	.string "Warning! One way cliffs!$"

RuggedRoadSouthSign_Text_0:
	.string "{UP_ARROW} Rugged Road$"

RuggedRoadCaveSign_Text_0:
	.string "Rugged Cave, beware of sudden\n"
	.string "temperature changes!$"

trainerSchooldKidRuggedRoad_Text_0:
	.string "I'm on my way back to Petalburg, but\n"
	.string "first let me test something I learned in\l"
	.string "school!$"

trainerSchooldKidRuggedRoad_Text_1:
	.string "I need to study harder...$"

trainerSchooldKidRuggedRoad_Text_2:
	.string "Have you already challenged Roxanne?\n"
	.string "She sometimes visits the trainer school\l"
	.string "to teach us!$"

trainerHikerRuggedRoad_Text_0:
	.string "I hear there is a cave around here, did\n"
	.string "you see it?$"

trainerHikerRuggedRoad_Text_1:
	.string "I might've missed it...$"

trainerHikerRuggedRoad_Text_2:
	.string "I wanted to see if there were any rare\n"
	.string "ice Pokémon inside the Rugged Cave.$"

trainerPicnickerRuggedRoad_Text_0:
	.string "Are you perhaps lost?$"

trainerPicnickerRuggedRoad_Text_1:
	.string "Right on the track!$"

trainerPicnickerRuggedRoad_Text_2:
	.string "I hear people sometimes drop items when\n"
	.string "admiring the flowers here.$"

trainerCamperRuggedRoad_Text_0:
	.string "Hey there! Let's have a fun battle to\n"
	.string "break up this trip$"

trainerCamperRuggedRoad_Text_1:
	.string "Nothing like a good battle!$"

trainerCamperRuggedRoad_Text_2:
	.string "Short camping trips can be very\n"
	.string "refreshing for body and mind!$"
